/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Oct 29 08:17:21 EDT 2017 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 9 -name t1buv_9 -include dft/simd/t1bu.h -sign 1 */

/*
 * This function contains 54 FP additions, 54 FP multiplications,
 * (or, 20 additions, 20 multiplications, 34 fused multiply/add),
 * 50 stack variables, 19 constants, and 18 memory accesses
 */
#include "dft/simd/t1bu.h"

static void t1buv_9(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DVK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DVK(KP879385241, +0.879385241571816768108218554649462939872416269);
     DVK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DVK(KP666666666, +0.666666666666666666666666666666666666666666667);
     DVK(KP673648177, +0.673648177666930348851716626769314796000375677);
     DVK(KP898197570, +0.898197570222573798468955502359086394667167570);
     DVK(KP826351822, +0.826351822333069651148283373230685203999624323);
     DVK(KP420276625, +0.420276625461206169731530603237061658838781920);
     DVK(KP907603734, +0.907603734547952313649323976213898122064543220);
     DVK(KP347296355, +0.347296355333860697703433253538629592000751354);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP152703644, +0.152703644666139302296566746461370407999248646);
     DVK(KP968908795, +0.968908795874236621082202410917456709164223497);
     DVK(KP203604859, +0.203604859554852403062088995281827210665664861);
     DVK(KP726681596, +0.726681596905677465811651808188092531873167623);
     DVK(KP439692620, +0.439692620785908384054109277324731469936208134);
     DVK(KP586256827, +0.586256827714544512072145703099641959914944179);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 16)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 16), MAKE_VOLATILE_STRIDE(9, rs)) {
	       V T1, T6, Tx, TO, TP, Tf, Tp, Tk, Tl, Tq, Tu, TD, TC, TA, Tz;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       {
		    V T3, T5, T2, T4;
		    T2 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
		    T3 = BYTW(&(W[TWVL * 4]), T2);
		    T4 = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
		    T5 = BYTW(&(W[TWVL * 10]), T4);
		    T6 = VADD(T3, T5);
		    Tx = VSUB(T3, T5);
	       }
	       {
		    V T9, Tn, Tb, Td, Te, Th, Tj, To, T8, Tm;
		    T8 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
		    T9 = BYTW(&(W[TWVL * 2]), T8);
		    Tm = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
		    Tn = BYTW(&(W[0]), Tm);
		    {
			 V Ta, Tc, Tg, Ti;
			 Ta = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 Tb = BYTW(&(W[TWVL * 8]), Ta);
			 Tc = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 Td = BYTW(&(W[TWVL * 14]), Tc);
			 Te = VADD(Tb, Td);
			 Tg = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 Th = BYTW(&(W[TWVL * 6]), Tg);
			 Ti = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Tj = BYTW(&(W[TWVL * 12]), Ti);
			 To = VADD(Th, Tj);
		    }
		    TO = VADD(Tn, To);
		    TP = VADD(T9, Te);
		    Tf = VFNMS(LDK(KP500000000), Te, T9);
		    Tp = VFNMS(LDK(KP500000000), To, Tn);
		    Tk = VSUB(Th, Tj);
		    Tl = VSUB(Td, Tb);
		    Tq = VFNMS(LDK(KP586256827), Tp, Tl);
		    Tu = VFNMS(LDK(KP439692620), Tk, Tf);
		    TD = VFNMS(LDK(KP726681596), Tk, Tp);
		    TC = VFMA(LDK(KP203604859), Tf, Tl);
		    TA = VFMA(LDK(KP968908795), Tp, Tk);
		    Tz = VFNMS(LDK(KP152703644), Tl, Tf);
	       }
	       {
		    V TS, TN, TQ, TR;
		    TS = VMUL(LDK(KP866025403), VSUB(TO, TP));
		    TN = VADD(T1, T6);
		    TQ = VADD(TO, TP);
		    TR = VFNMS(LDK(KP500000000), TQ, TN);
		    ST(&(x[WS(rs, 3)]), VFMAI(TS, TR), ms, &(x[WS(rs, 1)]));
		    ST(&(x[0]), VADD(TQ, TN), ms, &(x[0]));
		    ST(&(x[WS(rs, 6)]), VFNMSI(TS, TR), ms, &(x[0]));
	       }
	       {
		    V Ts, Tw, TJ, TM, T7, TF, TL, Tr, Tv;
		    Tr = VFNMS(LDK(KP347296355), Tq, Tk);
		    Ts = VFNMS(LDK(KP907603734), Tr, Tf);
		    Tv = VFNMS(LDK(KP420276625), Tu, Tl);
		    Tw = VFNMS(LDK(KP826351822), Tv, Tp);
		    {
			 V TH, TI, TE, TB;
			 TH = VFNMS(LDK(KP898197570), TD, TC);
			 TI = VFMA(LDK(KP673648177), TA, Tz);
			 TJ = VFMA(LDK(KP666666666), TI, TH);
			 TM = VMUL(LDK(KP984807753), VFMA(LDK(KP879385241), Tx, TI));
			 T7 = VFNMS(LDK(KP500000000), T6, T1);
			 TE = VFMA(LDK(KP898197570), TD, TC);
			 TB = VFNMS(LDK(KP673648177), TA, Tz);
			 TF = VFNMS(LDK(KP500000000), TE, TB);
			 TL = VFMA(LDK(KP852868531), TE, T7);
		    }
		    ST(&(x[WS(rs, 1)]), VFMAI(TM, TL), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 8)]), VFNMSI(TM, TL), ms, &(x[0]));
		    {
			 V Tt, Ty, TG, TK;
			 Tt = VFNMS(LDK(KP939692620), Ts, T7);
			 Ty = VMUL(LDK(KP984807753), VFNMS(LDK(KP879385241), Tx, Tw));
			 ST(&(x[WS(rs, 7)]), VFNMSI(Ty, Tt), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 2)]), VFMAI(Ty, Tt), ms, &(x[0]));
			 TG = VFMA(LDK(KP852868531), TF, T7);
			 TK = VMUL(LDK(KP866025403), VFNMS(LDK(KP852868531), TJ, Tx));
			 ST(&(x[WS(rs, 4)]), VFMAI(TK, TG), ms, &(x[0]));
			 ST(&(x[WS(rs, 5)]), VFNMSI(TK, TG), ms, &(x[WS(rs, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 9, XSIMD_STRING("t1buv_9"), twinstr, &GENUS, {20, 20, 34, 0}, 0, 0, 0 };

void XSIMD(codelet_t1buv_9) (planner *p) {
     X(kdft_dit_register) (p, t1buv_9, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 9 -name t1buv_9 -include dft/simd/t1bu.h -sign 1 */

/*
 * This function contains 54 FP additions, 42 FP multiplications,
 * (or, 38 additions, 26 multiplications, 16 fused multiply/add),
 * 38 stack variables, 14 constants, and 18 memory accesses
 */
#include "dft/simd/t1bu.h"

static void t1buv_9(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DVK(KP296198132, +0.296198132726023843175338011893050938967728390);
     DVK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DVK(KP173648177, +0.173648177666930348851716626769314796000375677);
     DVK(KP556670399, +0.556670399226419366452912952047023132968291906);
     DVK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DVK(KP642787609, +0.642787609686539326322643409907263432907559884);
     DVK(KP663413948, +0.663413948168938396205421319635891297216863310);
     DVK(KP150383733, +0.150383733180435296639271897612501926072238258);
     DVK(KP342020143, +0.342020143325668733044099614682259580763083368);
     DVK(KP813797681, +0.813797681349373692844693217248393223289101568);
     DVK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 16)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 16), MAKE_VOLATILE_STRIDE(9, rs)) {
	       V T1, T6, Tu, Tg, Tf, TD, Tq, Tp, TE;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       {
		    V T3, T5, T2, T4;
		    T2 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
		    T3 = BYTW(&(W[TWVL * 4]), T2);
		    T4 = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
		    T5 = BYTW(&(W[TWVL * 10]), T4);
		    T6 = VADD(T3, T5);
		    Tu = VMUL(LDK(KP866025403), VSUB(T3, T5));
	       }
	       {
		    V T9, Td, Tb, T8, Tc, Ta, Te;
		    T8 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
		    T9 = BYTW(&(W[0]), T8);
		    Tc = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
		    Td = BYTW(&(W[TWVL * 12]), Tc);
		    Ta = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    Tb = BYTW(&(W[TWVL * 6]), Ta);
		    Tg = VSUB(Tb, Td);
		    Te = VADD(Tb, Td);
		    Tf = VFNMS(LDK(KP500000000), Te, T9);
		    TD = VADD(T9, Te);
	       }
	       {
		    V Tj, Tn, Tl, Ti, Tm, Tk, To;
		    Ti = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
		    Tj = BYTW(&(W[TWVL * 2]), Ti);
		    Tm = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
		    Tn = BYTW(&(W[TWVL * 14]), Tm);
		    Tk = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    Tl = BYTW(&(W[TWVL * 8]), Tk);
		    Tq = VSUB(Tl, Tn);
		    To = VADD(Tl, Tn);
		    Tp = VFNMS(LDK(KP500000000), To, Tj);
		    TE = VADD(Tj, To);
	       }
	       {
		    V TF, TG, TH, TI;
		    TF = VBYI(VMUL(LDK(KP866025403), VSUB(TD, TE)));
		    TG = VADD(T1, T6);
		    TH = VADD(TD, TE);
		    TI = VFNMS(LDK(KP500000000), TH, TG);
		    ST(&(x[WS(rs, 3)]), VADD(TF, TI), ms, &(x[WS(rs, 1)]));
		    ST(&(x[0]), VADD(TG, TH), ms, &(x[0]));
		    ST(&(x[WS(rs, 6)]), VSUB(TI, TF), ms, &(x[0]));
	       }
	       {
		    V TC, Tv, Tw, Tx, Th, Tr, Ts, T7, TB;
		    TC = VBYI(VSUB(VFMA(LDK(KP984807753), Tf, VFMA(LDK(KP813797681), Tq, VFNMS(LDK(KP150383733), Tg, VMUL(LDK(KP342020143), Tp)))), Tu));
		    Tv = VFMA(LDK(KP663413948), Tg, VMUL(LDK(KP642787609), Tf));
		    Tw = VFMA(LDK(KP150383733), Tq, VMUL(LDK(KP984807753), Tp));
		    Tx = VADD(Tv, Tw);
		    Th = VFNMS(LDK(KP556670399), Tg, VMUL(LDK(KP766044443), Tf));
		    Tr = VFNMS(LDK(KP852868531), Tq, VMUL(LDK(KP173648177), Tp));
		    Ts = VADD(Th, Tr);
		    T7 = VFNMS(LDK(KP500000000), T6, T1);
		    TB = VFMA(LDK(KP852868531), Tg, VFMA(LDK(KP173648177), Tf, VFMA(LDK(KP296198132), Tq, VFNMS(LDK(KP939692620), Tp, T7))));
		    ST(&(x[WS(rs, 7)]), VSUB(TB, TC), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 2)]), VADD(TB, TC), ms, &(x[0]));
		    {
			 V Tt, Ty, Tz, TA;
			 Tt = VADD(T7, Ts);
			 Ty = VBYI(VADD(Tu, Tx));
			 ST(&(x[WS(rs, 8)]), VSUB(Tt, Ty), ms, &(x[0]));
			 ST(&(x[WS(rs, 1)]), VADD(Tt, Ty), ms, &(x[WS(rs, 1)]));
			 Tz = VBYI(VADD(Tu, VFNMS(LDK(KP500000000), Tx, VMUL(LDK(KP866025403), VSUB(Th, Tr)))));
			 TA = VFMA(LDK(KP866025403), VSUB(Tw, Tv), VFNMS(LDK(KP500000000), Ts, T7));
			 ST(&(x[WS(rs, 4)]), VADD(Tz, TA), ms, &(x[0]));
			 ST(&(x[WS(rs, 5)]), VSUB(TA, Tz), ms, &(x[WS(rs, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 9, XSIMD_STRING("t1buv_9"), twinstr, &GENUS, {38, 26, 16, 0}, 0, 0, 0 };

void XSIMD(codelet_t1buv_9) (planner *p) {
     X(kdft_dit_register) (p, t1buv_9, &desc);
}
#endif
