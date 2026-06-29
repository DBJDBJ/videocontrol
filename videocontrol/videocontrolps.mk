
videocontrolps.dll: dlldata.obj videocontrol_p.obj videocontrol_i.obj
	link /dll /out:videocontrolps.dll /def:videocontrolps.def /entry:DllMain dlldata.obj videocontrol_p.obj videocontrol_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del videocontrolps.dll
	@del videocontrolps.lib
	@del videocontrolps.exp
	@del dlldata.obj
	@del videocontrol_p.obj
	@del videocontrol_i.obj
