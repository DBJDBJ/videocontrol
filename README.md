# videocontrol by dbj.systems (circa 2005)

`DBJVIDEO` — an ATL-based ActiveX control (COM/OLE) by DBJSystems Ltd, wrapping
DirectShow (`quartz`) for embedding video rendering in a webpage or any
ActiveX host.

- Language: C++ (ATL/COM)
- Interfaces: `Idbjvideo`, `_IdbjvideoEvents`
- CLSID: `A3014D0A-95BE-4440-8D05-BEBC1117EBC6`
- Category: Safe for Scripting / Safe for Initializing
- Toolchain: originally built with Visual C++ 7 (VS .NET 2003), includes both
  `.dsp`/`.dsw` (VC6-style) and `.sln`/`.vcproj` (VS2003) project files

## Contents

- [videocontrol/](videocontrol/) — source: ATL control implementation
  (`dbjvideo.h/.cpp`), DirectShow type library wrappers (`quartz.tlh/.tli`),
  IDL (`videocontrol.idl`) and generated proxy/stub code
- [videocontrol/videocontrol.htm](videocontrol/videocontrol.htm) — sample HTML
  page embedding the control via `<OBJECT>`

## Building

Open `videocontrol/videocontrol.sln` (or the legacy `videocontrol.dsw`) in a
Visual C++ environment with the DirectShow SDK (`quartz`/Windows SDK headers)
available, and build the `videocontrol` ATL DLL project.

## Registering

The built DLL is a COM in-process server and must be registered with
`regsvr32 videocontrol.dll` before use.

Authors: 

Mahmudul Hoque  `mhoque@gmail.com`
Dusan Jovanovic `dbjdbj@gmail.com` 
