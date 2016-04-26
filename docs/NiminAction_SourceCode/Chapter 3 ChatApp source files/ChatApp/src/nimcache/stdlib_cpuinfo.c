/* Generated by Nim Compiler v0.12.1 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w -pthread  -I/home/renzhen/Nim12.0/lib -o src/nimcache/stdlib_cpuinfo.o src/nimcache/stdlib_cpuinfo.c */
#define NIM_INTBITS 64

#include "nimbase.h"
#include <unistd.h>
N_NIMCALL(NI, ncpicountProcessors)(void);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_30201)(void);
static N_INLINE(void, popFrame)(void);
extern NIM_THREADVAR TFrame* frameptr_27442;

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI LOC1;
	LOC1 = 0;
	{
		if (!(frameptr_27442 == NIM_NIL)) goto LA4;
		LOC1 = ((NI) 0);
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = ((NI) ((NI16)((*frameptr_27442).calldepth + ((NI16) 1))));
	}
	LA2: ;
	(*s).calldepth = ((NI16) (LOC1));
	(*s).prev = frameptr_27442;
	frameptr_27442 = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9;
		stackoverflow_30201();
	}
	LA9: ;
}

static N_INLINE(void, popFrame)(void) {
	frameptr_27442 = (*frameptr_27442).prev;
}

N_NIMCALL(NI, ncpicountProcessors)(void) {
	NI result;
	nimfr("countProcessors", "cpuinfo.nim")
	result = 0;
	nimln(65, "cpuinfo.nim");
	result = sysconf(_SC_NPROCESSORS_ONLN);
	nimln(66, "cpuinfo.nim");
	{
		if (!(result <= ((NI) 0))) goto LA3;
		result = ((NI) 1);
	}
	LA3: ;
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_cpuinfoInit000)(void) {
	nimfr("cpuinfo", "cpuinfo.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_cpuinfoDatInit000)(void) {
}

