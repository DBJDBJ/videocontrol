# videocontrol by dbj.systems (circa 2005)

`DBJVIDEO` — an ATL-based ActiveX control (COM/OLE) by DBJSystems Ltd, intended
to embed video rendering in a web page (Internet Explorer) or any ActiveX host.
The control is built as a Windows in-process COM server (`videocontrol.dll`).

- **Language:** C++ (ATL / COM)
- **Component type:** In-process ActiveX control (windowed, `m_bWindowOnly = TRUE`)
- **Primary interface:** `Idbjvideo` (dual `IDispatch`)
- **Event interface:** `_IdbjvideoEvents` (currently empty)
- **CLSID:** `A3014D0A-95BE-4440-8D05-BEBC1117EBC6`
- **ProgID:** `DBJSYS.VIDEOCTL.1`
- **Type library:** `VIDEOCONTROLLib` (`7C4D00BD-B7D6-4EFF-A98D-D7BC0D9B733C`)
- **Categories:** Safe for Scripting, Safe for Initializing, plus a custom
  *DBJSystems LTD COM* component category
- **Toolchain:** originally Visual C++ 7 (VS .NET 2003); ships both legacy
  `.dsp`/`.dsw` (VC6-style) and `.sln`/`.vcproj` (VS2003) project files

## Current state (review summary)

This repository is a **freshly generated ATL ActiveX skeleton** plus a stubbed
DirectShow integration point. Be aware before building on it:

- `Idbjvideo` exposes **only stock properties** — `BorderStyle`, `BorderWidth`,
  `HWND`, `MousePointer`, `MouseIcon`, `Picture`. There are no custom
  video-playback methods or properties (no source/URL, play, stop, seek).
- `Cdbjvideo::OnDrawAdvanced` paints a **placeholder rectangle** with its edge
  coordinates as text — it does not render video.
- `vrenderer` (`vrenderer.h`/`.cpp`) is an **empty class** (default
  constructor/destructor only). It `#include`s the DirectShow type-library
  wrapper `quartz.tlh`, but **no DirectShow interface is referenced anywhere**
  in the code (`IGraphBuilder`, `IMediaControl`, `IVideoWindow`, `IBasicVideo`,
  etc. are all unused).
- `_IdbjvideoEvents` declares no events.

In short: the **ActiveX/COM container scaffolding is complete and functional**
(registration, hosting, drawing surface, stock properties), but the
**DirectShow video pipeline is a planned integration that is not yet wired up**.
The diagrams below mark that boundary explicitly (dashed edges / "scaffold").

## Architecture (C4)

### Level 1 — System Context

Who and what the control interacts with at runtime.

```mermaid
C4Context
    title System Context — DBJVIDEO ActiveX Control

    Person(author, "Page Author / User", "Embeds the control via <OBJECT> and views it in an ActiveX host")

    System(dbjvideo, "DBJVIDEO ActiveX Control", "In-process COM server (videocontrol.dll) exposing an ActiveX video control surface")

    System_Ext(host, "ActiveX Host", "Internet Explorer / any OLE control container")
    System_Ext(com, "Windows COM Runtime + Registry", "Class activation, type-library and category registration")
    System_Ext(directshow, "DirectShow Runtime (quartz.dll)", "Intended media filter graph for video rendering")

    Rel(author, host, "Loads page")
    Rel(host, dbjvideo, "Activates", "COM/OLE")
    Rel(dbjvideo, com, "Registers with")
    Rel(dbjvideo, directshow, "Drives (planned)")
    UpdateRelStyle(dbjvideo, directshow, $lineStyle="dashed")
```

### Level 2 — Container

The single deployable in-process server and its supporting artifacts.

```mermaid
C4Container
    title Container — videocontrol.dll and supporting artifacts

    Person(author, "Page Author / User")
    System_Ext(host, "ActiveX Host (IE / OLE container)")
    System_Ext(directshow, "DirectShow (quartz.dll)")

    System_Boundary(server, "DBJVIDEO COM Server") {
        Container(dll, "videocontrol.dll", "ATL / C++ in-proc server", "Class factory + Cdbjvideo ActiveX control")
        Container(tlb, "videocontrol.tlb", "Type library", "Idbjvideo & _IdbjvideoEvents descriptions for hosts/scripting")
        Container(ps, "Proxy/Stub", "Generated C (videocontrol_p.c, dlldata.c)", "Cross-apartment marshalling (built via videocontrolps.mk)")
    }

    Rel(author, host, "Views page")
    Rel(host, dll, "Activates", "COM/OLE")
    Rel(host, tlb, "Reads metadata")
    Rel(dll, ps, "Marshals via")
    Rel(dll, directshow, "Renders (planned)")
    UpdateRelStyle(dll, directshow, $lineStyle="dashed")
```

### Level 3 — Component

Inside `videocontrol.dll`.

```mermaid
C4Component
    title Component — inside videocontrol.dll

    System_Ext(host, "ActiveX Host")
    System_Ext(directshow, "DirectShow (quartz.dll)")

    Container_Boundary(dll, "videocontrol.dll") {
        Component(exports, "DLL Exports", "videocontrol.cpp", "DllMain, DllGetClassObject, DllRegister/UnregisterServer; CComModule + OBJECT_MAP class factory")
        Component(control, "Cdbjvideo", "dbjvideo.h/.cpp (ATL CComControl)", "ActiveX control: COM map, stock property map, OnDrawAdvanced placeholder painting")
        Component(iface, "Idbjvideo / _IdbjvideoEvents", "videocontrol.idl → _i.c", "Dual IDispatch (stock props only); empty event dispinterface")
        Component(category, "DBJSystems Category", "dbjsyscomcategory.h / dbjsyscategory.cpp", "Custom COM component category GUID + registration")
        Component(reg, "Registration script", "dbjvideo.rgs", "ProgID, InprocServer32, Control, categories")
        Component(vrenderer, "vrenderer (scaffold)", "vrenderer.h/.cpp", "Empty class; include point for DirectShow")
        Component(quartz, "quartz wrappers", "quartz.tlh / quartz.tli", "Generated DirectShow type-library import (unused)")
    }

    Rel(host, exports, "Creates", "COM")
    Rel(exports, control, "Instantiates")
    Rel(control, iface, "Implements")
    Rel(control, category, "Declares")
    Rel(exports, reg, "Registers via")
    Rel(vrenderer, quartz, "Includes")
    Rel(control, vrenderer, "Owns (planned)")
    Rel(vrenderer, directshow, "Renders (planned)")
    UpdateRelStyle(control, vrenderer, $lineStyle="dashed")
    UpdateRelStyle(vrenderer, directshow, $lineStyle="dashed")
```

> **C4 Code level (Level 4)** is intentionally omitted — at this stage the
> implementation is thin (a single control class plus generated ATL/MIDL
> boilerplate), so the Component level already reflects the meaningful code
> structure.

## Repository layout

| Path | Role |
| --- | --- |
| `videocontrol/dbjvideo.h` / `dbjvideo.cpp` | The ATL ActiveX control `Cdbjvideo` (interface maps, property map, drawing) |
| `videocontrol/videocontrol.idl` | IDL defining `Idbjvideo`, `_IdbjvideoEvents`, `coclass dbjvideo` and the type library |
| `videocontrol/videocontrol.cpp` | DLL exports, `CComModule`, class object map (server entry points) |
| `videocontrol/vrenderer.h` / `vrenderer.cpp` | DirectShow renderer — **stub** (intended integration point) |
| `videocontrol/quartz.tlh` / `quartz.tli` | Generated DirectShow (`quartz.dll`) type-library wrappers |
| `videocontrol/dbjsyscomcategory.h` / `dbjsyscategory.cpp` | Custom *DBJSystems* COM component category GUID |
| `videocontrol/dbjvideo.rgs` | Registry script (ProgID, `InprocServer32`, control, categories) |
| `videocontrol/videocontrol_i.c` / `_p.c` / `dlldata.c` | MIDL-generated GUIDs and proxy/stub marshalling code |
| `videocontrol/videocontrol.{sln,vcproj}` / `{dsw,dsp}` | VS2003 and legacy VC6-style project files |
| `videocontrol/videocontrol.htm`, `dbjvideo.htm` | Sample HTML pages embedding the control via `<OBJECT>` |
| `videocontrol/StdAfx.h` / `StdAfx.cpp` | Precompiled-header / ATL module setup |

## Building

Open `videocontrol/videocontrol.sln` (or the legacy `videocontrol.dsw`) in a
Visual C++ environment with the DirectShow SDK (`quartz` / Windows SDK headers)
available, and build the `videocontrol` ATL DLL project. To build a separate
proxy/stub DLL, run `nmake -f videocontrolps.mk` in the project directory.

## Registering

The built DLL is a COM in-process server and must be registered before use:

```
regsvr32 videocontrol.dll
```

`DllRegisterServer` registers the coclass, type library, all interfaces in the
type library, and the custom DBJSystems component category. Use
`regsvr32 /u videocontrol.dll` to unregister.

## Hosting

Embed in an ActiveX host (e.g. Internet Explorer) via an `<OBJECT>` tag keyed on
the CLSID — see `videocontrol/videocontrol.htm`:

```html
<OBJECT id=dbjvx style="WIDTH: 754px; HEIGHT: 310px"
        classid="clsid:A3014D0A-95BE-4440-8D05-BEBC1117EBC6">
</OBJECT>
```

## Authors

- Mahmudul Hoque — `mhoque@gmail.com`
- Dusan Jovanovic — `dbjdbj@gmail.com`
