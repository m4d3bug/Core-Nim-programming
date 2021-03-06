/* Generated by Nim Compiler v0.12.1 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w  -I/home/renzhen/Nim12.0/lib -o src/nimcache/stdlib_hashes.o src/nimcache/stdlib_hashes.c */
#define NIM_INTBITS 64

#include "nimbase.h"
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_NIMCALL_PTR(void, TY3889) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, TY3894) (void* p);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY3889 marker;
TY3894 deepcopy;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
static N_INLINE(NI, HEX21HEX26_144013)(NI h, NI val);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_23601)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(NI, HEX21HEX24_144042)(NI h);
N_NIMCALL(NI, hashdata_144070)(void* data, NI size);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, subInt)(NI a, NI b);
static N_INLINE(NI, hash_144401)(void* x);
static N_INLINE(NI, hash_144804)(NI x);
static N_INLINE(NI, hash_144814)(NI64 x);
static N_INLINE(NI, hash_144824)(NIM_CHAR x);
N_NIMCALL(NI, hash_144851)(NimStringDesc* x);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(NI, hash_144899)(NimStringDesc* sbuf, NI spos, NI epos);
N_NIMCALL(NI, hashignorestyle_144948)(NimStringDesc* x);
static N_INLINE(NIM_BOOL, ismagicidentseparatorrune_143020)(NCSTRING cs, NI i);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
N_NIMCALL(NI, hashignorestyle_145043)(NimStringDesc* sbuf, NI spos, NI epos);
N_NIMCALL(NI, hashignorecase_145139)(NimStringDesc* x);
N_NIMCALL(NI, hashignorecase_145226)(NimStringDesc* sbuf, NI spos, NI epos);
static N_INLINE(NI, hash_145314)(NF x);
extern TFrame* frameptr_20842;
TNimType NTI144005; /* Hash */

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI LOC1;
	LOC1 = 0;
	{
		if (!(frameptr_20842 == NIM_NIL)) goto LA4;
		LOC1 = ((NI) 0);
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = ((NI) ((NI16)((*frameptr_20842).calldepth + ((NI16) 1))));
	}
	LA2: ;
	(*s).calldepth = ((NI16) (LOC1));
	(*s).prev = frameptr_20842;
	frameptr_20842 = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9;
		stackoverflow_23601();
	}
	LA9: ;
}

static N_INLINE(void, popFrame)(void) {
	frameptr_20842 = (*frameptr_20842).prev;
}

static N_INLINE(NI, HEX21HEX26_144013)(NI h, NI val) {
	NI result;
	nimfr("!&", "hashes.nim")
	result = 0;
	nimln(53, "hashes.nim");
	result = (NI)((NU64)(h) + (NU64)(val));
	nimln(54, "hashes.nim");
	result = (NI)((NU64)(result) + (NU64)((NI)((NU64)(result) << (NU64)(((NI) 10)))));
	nimln(55, "hashes.nim");
	result = (NI)(result ^ (NI)((NU64)(result) >> (NU64)(((NI) 6))));
	popFrame();
	return result;
}

static N_INLINE(NI, HEX21HEX24_144042)(NI h) {
	NI result;
	nimfr("!$", "hashes.nim")
	result = 0;
	nimln(60, "hashes.nim");
	result = (NI)((NU64)(h) + (NU64)((NI)((NU64)(h) << (NU64)(((NI) 3)))));
	nimln(61, "hashes.nim");
	result = (NI)(result ^ (NI)((NU64)(result) >> (NU64)(((NI) 11))));
	nimln(62, "hashes.nim");
	result = (NI)((NU64)(result) + (NU64)((NI)((NU64)(result) << (NU64)(((NI) 15)))));
	popFrame();
	return result;
}

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = 0;
	result = (NI)((NU64)(a) + (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (((NI) 0) <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (((NI) 0) <= (NI)(result ^ b));
		LA4: ;
		if (!LOC3) goto LA5;
		goto BeforeRet;
	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = 0;
	result = (NI)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (((NI) 0) <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (((NI) 0) <= (NI)(result ^ (NI)((NU64) ~(b))));
		LA4: ;
		if (!LOC3) goto LA5;
		goto BeforeRet;
	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NI, hashdata_144070)(void* data, NI size) {
	NI result;
	NI h;
	NCSTRING p;
	NI i;
	NI s;
	nimfr("hashData", "hashes.nim")
	result = 0;
	nimln(66, "hashes.nim");
	h = ((NI) 0);
	nimln(71, "hashes.nim");
	p = ((NCSTRING) (data));
	nimln(72, "hashes.nim");
	i = ((NI) 0);
	nimln(73, "hashes.nim");
	s = size;
	{
		nimln(74, "hashes.nim");
		while (1) {
			NI TMP555;
			NI TMP556;
			nimln(357, "system.nim");
			if (!(((NI) 0) < s)) goto LA2;
			nimln(75, "hashes.nim");
			h = HEX21HEX26_144013(h, ((NI) (((NU8)(p[i])))));
			nimln(76, "hashes.nim");
			TMP555 = addInt(i, ((NI) 1));
			i = (NI)(TMP555);
			nimln(77, "hashes.nim");
			TMP556 = subInt(s, ((NI) 1));
			s = (NI)(TMP556);
		} LA2: ;
	}
	nimln(78, "hashes.nim");
	result = HEX21HEX24_144042(h);
	popFrame();
	return result;
}

static N_INLINE(NI, hash_144401)(void* x) {
	NI result;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(97, "hashes.nim");
	result = (NI)((NU64)(((NI) (x))) >> (NU64)(((NI) 3)));
	popFrame();
	return result;
}

static N_INLINE(NI, hash_144804)(NI x) {
	NI result;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(109, "hashes.nim");
	result = x;
	popFrame();
	return result;
}

static N_INLINE(NI, hash_144814)(NI64 x) {
	NI result;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(113, "hashes.nim");
	result = ((NI) (((NI32)(NU32)(NU64)(x))));
	popFrame();
	return result;
}

static N_INLINE(NI, hash_144824)(NIM_CHAR x) {
	NI result;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(117, "hashes.nim");
	result = ((NI) (((NU8)(x))));
	popFrame();
	return result;
}

N_NIMCALL(NI, hash_144851)(NimStringDesc* x) {
	NI result;
	NI h;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(125, "hashes.nim");
	h = ((NI) 0);
	{
		NI i_144866;
		NI HEX3Atmp_144877;
		NI TMP557;
		NI res_144880;
		i_144866 = 0;
		HEX3Atmp_144877 = 0;
		nimln(126, "hashes.nim");
		TMP557 = subInt((x ? x->Sup.len : 0), ((NI) 1));
		HEX3Atmp_144877 = (NI)(TMP557);
		nimln(1874, "system.nim");
		res_144880 = ((NI) 0);
		{
			nimln(1875, "system.nim");
			while (1) {
				NI TMP558;
				if (!(res_144880 <= HEX3Atmp_144877)) goto LA3;
				nimln(1876, "system.nim");
				i_144866 = res_144880;
				nimln(127, "hashes.nim");
				if ((NU)(i_144866) > (NU)(x->Sup.len)) raiseIndexError();
				h = HEX21HEX26_144013(h, ((NI) (((NU8)(x->data[i_144866])))));
				nimln(1895, "system.nim");
				TMP558 = addInt(res_144880, ((NI) 1));
				res_144880 = (NI)(TMP558);
			} LA3: ;
		}
	}
	nimln(128, "hashes.nim");
	result = HEX21HEX24_144042(h);
	popFrame();
	return result;
}

N_NIMCALL(NI, hash_144899)(NimStringDesc* sbuf, NI spos, NI epos) {
	NI result;
	NI h;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(135, "hashes.nim");
	h = ((NI) 0);
	{
		NI i_144916;
		NI res_144929;
		i_144916 = 0;
		nimln(1874, "system.nim");
		res_144929 = spos;
		{
			nimln(1875, "system.nim");
			while (1) {
				NI TMP559;
				if (!(res_144929 <= epos)) goto LA3;
				nimln(1876, "system.nim");
				i_144916 = res_144929;
				nimln(137, "hashes.nim");
				if ((NU)(i_144916) > (NU)(sbuf->Sup.len)) raiseIndexError();
				h = HEX21HEX26_144013(h, ((NI) (((NU8)(sbuf->data[i_144916])))));
				nimln(1895, "system.nim");
				TMP559 = addInt(res_144929, ((NI) 1));
				res_144929 = (NI)(TMP559);
			} LA3: ;
		}
	}
	nimln(138, "hashes.nim");
	result = HEX21HEX24_144042(h);
	popFrame();
	return result;
}

static N_INLINE(NIM_BOOL, ismagicidentseparatorrune_143020)(NCSTRING cs, NI i) {
	NIM_BOOL result;
	NIM_BOOL LOC1;
	NIM_BOOL LOC2;
	NI TMP561;
	NI TMP562;
	nimfr("isMagicIdentSeparatorRune", "etcpriv.nim")
	result = 0;
	nimln(21, "etcpriv.nim");
	nimln(22, "etcpriv.nim");
	LOC1 = 0;
	nimln(21, "etcpriv.nim");
	LOC2 = 0;
	LOC2 = ((NU8)(cs[i]) == (NU8)(226));
	if (!(LOC2)) goto LA3;
	nimln(22, "etcpriv.nim");
	TMP561 = addInt(i, ((NI) 1));
	LOC2 = ((NU8)(cs[(NI)(TMP561)]) == (NU8)(128));
	LA3: ;
	LOC1 = LOC2;
	if (!(LOC1)) goto LA4;
	nimln(23, "etcpriv.nim");
	TMP562 = addInt(i, ((NI) 2));
	LOC1 = ((NU8)(cs[(NI)(TMP562)]) == (NU8)(147));
	LA4: ;
	result = LOC1;
	popFrame();
	return result;
}

static N_INLINE(NI, chckRange)(NI i, NI a, NI b) {
	NI result;
{	result = 0;
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (a <= i);
		if (!(LOC3)) goto LA4;
		LOC3 = (i <= b);
		LA4: ;
		if (!LOC3) goto LA5;
		result = i;
		goto BeforeRet;
	}
	goto LA1;
	LA5: ;
	{
		raiseRangeError(((NI64) (i)));
	}
	LA1: ;
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NI, hashignorestyle_144948)(NimStringDesc* x) {
	NI result;
	NI h;
	NI i;
	NI xlen;
	nimfr("hashIgnoreStyle", "hashes.nim")
	result = 0;
	nimln(142, "hashes.nim");
	h = ((NI) 0);
	nimln(143, "hashes.nim");
	i = ((NI) 0);
	nimln(144, "hashes.nim");
	xlen = (x ? x->Sup.len : 0);
	{
		nimln(145, "hashes.nim");
		while (1) {
			NIM_CHAR c;
			if (!(i < xlen)) goto LA2;
			nimln(146, "hashes.nim");
			if ((NU)(i) > (NU)(x->Sup.len)) raiseIndexError();
			c = x->data[i];
			nimln(147, "hashes.nim");
			{
				NI TMP560;
				if (!((NU8)(c) == (NU8)(95))) goto LA5;
				nimln(148, "hashes.nim");
				TMP560 = addInt(i, ((NI) 1));
				i = (NI)(TMP560);
			}
			goto LA3;
			LA5: ;
			{
				NIM_BOOL LOC8;
				NI TMP563;
				nimln(149, "hashes.nim");
				LOC8 = 0;
				LOC8 = ismagicidentseparatorrune_143020(x->data, i);
				if (!LOC8) goto LA9;
				nimln(150, "hashes.nim");
				TMP563 = addInt(i, ((NI) 3));
				i = (NI)(TMP563);
			}
			goto LA3;
			LA9: ;
			{
				NI TMP565;
				nimln(152, "hashes.nim");
				{
					NI TMP564;
					nimln(1098, "system.nim");
					if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA14;
					nimln(153, "hashes.nim");
					TMP564 = addInt(((NI) (((NU8)(c)))), ((NI) 32));
					c = ((NIM_CHAR) (((NI)chckRange((NI)(TMP564), ((NI) 0), ((NI) 255)))));
				}
				LA14: ;
				nimln(154, "hashes.nim");
				h = HEX21HEX26_144013(h, ((NI) (((NU8)(c)))));
				nimln(155, "hashes.nim");
				TMP565 = addInt(i, ((NI) 1));
				i = (NI)(TMP565);
			}
			LA3: ;
		} LA2: ;
	}
	nimln(157, "hashes.nim");
	result = HEX21HEX24_144042(h);
	popFrame();
	return result;
}

N_NIMCALL(NI, hashignorestyle_145043)(NimStringDesc* sbuf, NI spos, NI epos) {
	NI result;
	NI h;
	NI i;
	nimfr("hashIgnoreStyle", "hashes.nim")
	result = 0;
	nimln(165, "hashes.nim");
	h = ((NI) 0);
	nimln(166, "hashes.nim");
	i = spos;
	{
		nimln(167, "hashes.nim");
		while (1) {
			NIM_CHAR c;
			if (!(i <= epos)) goto LA2;
			nimln(168, "hashes.nim");
			if ((NU)(i) > (NU)(sbuf->Sup.len)) raiseIndexError();
			c = sbuf->data[i];
			nimln(169, "hashes.nim");
			{
				NI TMP566;
				if (!((NU8)(c) == (NU8)(95))) goto LA5;
				nimln(170, "hashes.nim");
				TMP566 = addInt(i, ((NI) 1));
				i = (NI)(TMP566);
			}
			goto LA3;
			LA5: ;
			{
				NIM_BOOL LOC8;
				NI TMP567;
				nimln(171, "hashes.nim");
				LOC8 = 0;
				LOC8 = ismagicidentseparatorrune_143020(sbuf->data, i);
				if (!LOC8) goto LA9;
				nimln(172, "hashes.nim");
				TMP567 = addInt(i, ((NI) 3));
				i = (NI)(TMP567);
			}
			goto LA3;
			LA9: ;
			{
				NI TMP569;
				nimln(174, "hashes.nim");
				{
					NI TMP568;
					nimln(1098, "system.nim");
					if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA14;
					nimln(175, "hashes.nim");
					TMP568 = addInt(((NI) (((NU8)(c)))), ((NI) 32));
					c = ((NIM_CHAR) (((NI)chckRange((NI)(TMP568), ((NI) 0), ((NI) 255)))));
				}
				LA14: ;
				nimln(176, "hashes.nim");
				h = HEX21HEX26_144013(h, ((NI) (((NU8)(c)))));
				nimln(177, "hashes.nim");
				TMP569 = addInt(i, ((NI) 1));
				i = (NI)(TMP569);
			}
			LA3: ;
		} LA2: ;
	}
	nimln(178, "hashes.nim");
	result = HEX21HEX24_144042(h);
	popFrame();
	return result;
}

N_NIMCALL(NI, hashignorecase_145139)(NimStringDesc* x) {
	NI result;
	NI h;
	nimfr("hashIgnoreCase", "hashes.nim")
	result = 0;
	nimln(182, "hashes.nim");
	h = ((NI) 0);
	{
		NI i_145154;
		NI HEX3Atmp_145204;
		NI TMP570;
		NI res_145207;
		i_145154 = 0;
		HEX3Atmp_145204 = 0;
		nimln(183, "hashes.nim");
		TMP570 = subInt((x ? x->Sup.len : 0), ((NI) 1));
		HEX3Atmp_145204 = (NI)(TMP570);
		nimln(1874, "system.nim");
		res_145207 = ((NI) 0);
		{
			nimln(1875, "system.nim");
			while (1) {
				NIM_CHAR c;
				NI TMP572;
				if (!(res_145207 <= HEX3Atmp_145204)) goto LA3;
				nimln(1876, "system.nim");
				i_145154 = res_145207;
				nimln(184, "hashes.nim");
				if ((NU)(i_145154) > (NU)(x->Sup.len)) raiseIndexError();
				c = x->data[i_145154];
				nimln(185, "hashes.nim");
				{
					NI TMP571;
					nimln(1098, "system.nim");
					if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA6;
					nimln(186, "hashes.nim");
					TMP571 = addInt(((NI) (((NU8)(c)))), ((NI) 32));
					c = ((NIM_CHAR) (((NI)chckRange((NI)(TMP571), ((NI) 0), ((NI) 255)))));
				}
				LA6: ;
				nimln(187, "hashes.nim");
				h = HEX21HEX26_144013(h, ((NI) (((NU8)(c)))));
				nimln(1895, "system.nim");
				TMP572 = addInt(res_145207, ((NI) 1));
				res_145207 = (NI)(TMP572);
			} LA3: ;
		}
	}
	nimln(188, "hashes.nim");
	result = HEX21HEX24_144042(h);
	popFrame();
	return result;
}

N_NIMCALL(NI, hashignorecase_145226)(NimStringDesc* sbuf, NI spos, NI epos) {
	NI result;
	NI h;
	nimfr("hashIgnoreCase", "hashes.nim")
	result = 0;
	nimln(196, "hashes.nim");
	h = ((NI) 0);
	{
		NI i_145243;
		NI res_145295;
		i_145243 = 0;
		nimln(1874, "system.nim");
		res_145295 = spos;
		{
			nimln(1875, "system.nim");
			while (1) {
				NIM_CHAR c;
				NI TMP574;
				if (!(res_145295 <= epos)) goto LA3;
				nimln(1876, "system.nim");
				i_145243 = res_145295;
				nimln(198, "hashes.nim");
				if ((NU)(i_145243) > (NU)(sbuf->Sup.len)) raiseIndexError();
				c = sbuf->data[i_145243];
				nimln(199, "hashes.nim");
				{
					NI TMP573;
					nimln(1098, "system.nim");
					if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA6;
					nimln(200, "hashes.nim");
					TMP573 = addInt(((NI) (((NU8)(c)))), ((NI) 32));
					c = ((NIM_CHAR) (((NI)chckRange((NI)(TMP573), ((NI) 0), ((NI) 255)))));
				}
				LA6: ;
				nimln(201, "hashes.nim");
				h = HEX21HEX26_144013(h, ((NI) (((NU8)(c)))));
				nimln(1895, "system.nim");
				TMP574 = addInt(res_145295, ((NI) 1));
				res_145295 = (NI)(TMP574);
			} LA3: ;
		}
	}
	nimln(202, "hashes.nim");
	result = HEX21HEX24_144042(h);
	popFrame();
	return result;
}

static N_INLINE(NI, hash_145314)(NF x) {
	NI result;
	NF y;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(206, "hashes.nim");
	y = ((NF)(x) + (NF)(1.0000000000000000e+00));
	nimln(207, "hashes.nim");
	result = (*((NI*) ((&y))));
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_hashesInit000)(void) {
	nimfr("hashes", "hashes.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_hashesDatInit000)(void) {
NTI144005.size = sizeof(NI);
NTI144005.kind = 31;
NTI144005.base = 0;
NTI144005.flags = 3;
}

