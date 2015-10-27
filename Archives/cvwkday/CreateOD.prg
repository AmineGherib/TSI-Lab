new;

chdir C:\EnvCan\Windsor\ODs\2006\cvwkday;

z=70;/*number of zones*/

load jobs[z,12]=jobs_tab.txt;

/*
columns in the table are"
col1: zone id
col2: Total - Occupation - National Occupational Classification for Statistics 2006	  
col3: A Management occupations	  
col4: B Business, finance and administrative occupations	  
col5: C Natural and applied sciences and related occupations	  
col6: D Health occupations	  
col7: E Occupations in social science, education, government service and religion	  
col8: F Occupations in art, culture, recreation and sport	  
col9: G Sales and service occupations	  
col10: H Trades, transport and equipment operators and related occupations	  
col11: I Occupations unique to primary industry	  
col12: J Occupations unique to processing, manufacturing and utilities

*/


/*Calculating the covariates needed to calculate the OD martices*/

X1=jobs[.,10]+jobs[.,12];
X2=jobs[.,9];
W1j=jobs[.,2];
W2j=jobs[.,10]+jobs[.,12];
W3j=jobs[.,10]+jobs[.,11]+jobs[.,12];


/*Trip generation beta B parameters*/

Lam_B1=0.08421129;
Lam_B2=0.08694855;
Lpm_B1=0.07228640;
Lpm_B2=0.07443733;
Lof_B1=0.48924490;
Lof_B2=0.51566270;

mam_B1=0.06440935;
mam_B2=0.05106377;
mpm_B1=0.03770727;
mpm_B2=0.03890285;
mof_B1=0.26768960;
mof_B2=0.27289150;

ham_B1=0.05037344;
hpm_B1=0.01889053;
hof_B1=0.14541720;

/*Calculating trip generation (productions) for light, medium and heavy duty during AM, PM and off peak periods*/


/*Adjustment factors to conform to the totals in the 33 x 33 aggregate observed data

1.21 	 1.23 	 1.14 	 1.21 	 1.49 	 1.23 	 1.92 	 3.92 	 2.31 

*/

Loi_am=((Lam_B1*X1)+(Lam_B2*X2)).* 1.21;
Loi_pm=((Lpm_B1*X1)+(Lpm_B2*X2)) .* 1.23;
Loi_of=((Lof_B1*X1)+(Lof_B2*X2)) .* 1.14;

Moi_am=((mam_B1*X1)+(mam_B2*X2)) .* 1.21;
Moi_pm=((mpm_B1*X1)+(mpm_B2*X2)) .* 1.49;
Moi_of=((mof_B1*X1)+(mof_B2*X2)) .* 1.23;

Hoi_am=(ham_B1*X1) .* 1.92;
Hoi_pm=(hpm_B1*X1) .* 3.92;
Hoi_of=(hof_B1*X1) .* 2.31;


 






/*
sumc(Loi_am);
sumc(Loi_pm);
sumc(Loi_of);
sumc(moi_am);
sumc(moi_pm);
sumc(moi_of);
sumc(hoi_am);
sumc(hoi_pm);
sumc(hoi_of);
*/



/*Creating the table with originating zones*/
Oi=Loi_am~Loi_pm~Loi_of~moi_am~moi_pm~moi_of~hoi_am~hoi_pm~hoi_of;

/*Calculating the 9 OD matrices for light, medium and heavy CVs for AM peak, PM peak and off peak periods*/

load timesij[z,z]=timesij.txt;

/*
load Ai[z,4]=employment.txt;col 1: total jobs "JOBS"; col2: X2 "TR_A_MA"; 
col3: X3: Retail; X4: X1+X2 "BASIC employment"*/

Ai=zeros(z,4);

Ai[.,1]=W1j;
Ai[.,2]=W2j;
Ai[.,4]=W3j;

/*
load Oi[z,9]=Oi.txt;
*/
/*
Oi summarize the trip generation results for 3 classes of commerical vehicles: Light, medium and Heavy
for 3 period of day: AM peak, PM peak, off peak periods. 
Col1: L_AM_Peak	(Light am peak)
Col2: L_PM_Peak	(Light pm peak)
Col3: L_OF_Peak	(Light off peak)
Col4: M_AM_Peak	(Medium am peak)
Col5: M_PM_Peak	(Medium pm peak)
Col6: M_OF_Peak	(Medium off peak)
Col7: H_AM_Peak	(Heavy am peak)
Col8: H_PM_Peak	(Heavy pm peak)
Col9: H_OF_Peak (Heavy off peak)
*/
/*Declaring Beta values associated with the travel times variable*/

beta1=-0.125579;                  /*L_AM_Peak_beta*/
beta2=-0.079949;                  /*L_PM_Peak_beta*/	
beta3=-0.617672;                  /*L_OF_Peak_beta*/	
beta4=-0.052694;                  /*M_AM_Peak_beta*/	
beta5=-0.034611;                  /*M_PM_Peak_beta*/	
beta6=-0.435597;                  /*M_OF_Peak_beta*/	
beta7=-0.032460;                  /*H_AM_Peak_beta*/	
beta8=-0.059109;                  /*H_PM_Peak_beta*/	
beta9=-0.058830;                  /*H_OF_Peak_beta*/

/*Declaring alpha values associated with the attractivness variable*/

alpha1=0.156972;                  /*L_AM_Peak_alpha associated with total jobs Ai[.,1]*/
alpha2=0.147970;                  /*L_PM_Peak_alpha associated with X2 Ai[.,2]*/	
alpha3=1.192275;                  /*L_OF_Peak_alpha associated with total jobs Ai[.,1]*/	
alpha4=0.123535;                  /*M_AM_Peak_alpha associated with basic jobs Ai[.,4]*/	
alpha5=0.061130;                  /*M_PM_Peak_alpha associated with basic jobs Ai[.,4]*/	
alpha6=0.651342;                  /*M_OF_Peak_alpha associated with basic jobs Ai[.,4]*/	
alpha7=0.123193;                  /*H_AM_Peak_alpha associated with basic jobs Ai[.,4]*/	
alpha8=0.303712;                  /*H_PM_Peak_alpha associated with basic jobs Ai[.,4]*/	
alpha9=0.295992;                  /*H_OF_Peak_alpha associated with basic jobs Ai[.,4]*/


/*calculating the attractivness measure Wj^alpha*/
WJ1=Ai[.,1]^alpha1;
WJ2=Ai[.,2]^alpha2;
WJ3=Ai[.,1]^alpha3;
WJ4=Ai[.,4]^alpha4;
WJ5=Ai[.,4]^alpha5;
WJ6=Ai[.,4]^alpha6;
WJ7=Ai[.,4]^alpha7;
WJ8=Ai[.,4]^alpha8;
WJ9=Ai[.,4]^alpha9;

/*calculating the impedance matrix exp(-beta*timesij)*/

expb1=exp(beta1 .* timesij);
expb2=exp(beta2 .* timesij);
expb3=exp(beta3 .* timesij);
expb4=exp(beta4 .* timesij);
expb5=exp(beta5 .* timesij);
expb6=exp(beta6 .* timesij);
expb7=exp(beta7 .* timesij);
expb8=exp(beta8 .* timesij);
expb9=exp(beta9 .* timesij);

/*calculating the matrix Wj^alpha * exp(-beta*timesij)*/
wexp1=(WJ1 .* expb1')';
wexp2=(WJ2 .* expb2')';
wexp3=(WJ3 .* expb3')';
wexp4=(WJ4 .* expb4')';
wexp5=(WJ5 .* expb5')';
wexp6=(WJ6 .* expb6')';
wexp7=(WJ7 .* expb7')';
wexp8=(WJ8 .* expb8')';
wexp9=(WJ9 .* expb9')';

/*calculating the vector of totals sum over k (Wk^alpha * exp(-beta * timesik)) */
sum_wexp1=sumc(wexp1');
sum_wexp2=sumc(wexp2');
sum_wexp3=sumc(wexp3');
sum_wexp4=sumc(wexp4');
sum_wexp5=sumc(wexp5');
sum_wexp6=sumc(wexp6');
sum_wexp7=sumc(wexp7');
sum_wexp8=sumc(wexp8');
sum_wexp9=sumc(wexp9');


/*calculating probabilities for distributing generated trips by zone*/

Prij1=wexp1 ./ sum_wexp1;
Prij2=wexp2 ./ sum_wexp2;
Prij3=wexp3 ./ sum_wexp3;
Prij4=wexp4 ./ sum_wexp4;
Prij5=wexp5 ./ sum_wexp5;
Prij6=wexp6 ./ sum_wexp6;
Prij7=wexp7 ./ sum_wexp7;
Prij8=wexp8 ./ sum_wexp8;
Prij9=wexp9 ./ sum_wexp9;


/*Creating OD matrices for commericial vehicles*/

/*Light commerical vehicles*/

L_OD_AM = Oi[.,1] .* Prij1;
L_OD_PM = Oi[.,2] .* Prij2;
L_OD_OFF =Oi[.,3] .* Prij3;

/*Medium commerical vehicles*/

M_OD_AM = Oi[.,4] .* Prij4;
M_OD_PM = Oi[.,5] .* Prij5;
M_OD_OFF= Oi[.,6] .* Prij6;


/*Heavy commerical vehicles*/

H_OD_AM = Oi[.,7] .* Prij7;
H_OD_PM = Oi[.,8] .* Prij8;
H_OD_OFF= Oi[.,9] .* Prij9;





sumc(sumc(L_OD_AM));
sumc(sumc(L_OD_PM));
sumc(sumc(L_OD_OFF));
sumc(sumc(M_OD_AM));
sumc(sumc(M_OD_PM));
sumc(sumc(M_OD_OFF));
sumc(sumc(H_OD_AM));
sumc(sumc(H_OD_PM));
sumc(sumc(H_OD_OFF));


export(L_OD_AM,"L_OD_AM.txt",1);
export(L_OD_PM,"L_OD_PM.txt",1);
export(L_OD_OFF,"L_OD_OFF.txt",1);
export(M_OD_AM,"M_OD_AM.txt",1);
export(M_OD_PM,"M_OD_PM.txt",1);
export(M_OD_OFF,"M_OD_OFF.txt",1);
export(H_OD_AM,"H_OD_AM.txt",1);
export(H_OD_PM,"H_OD_PM.txt",1);
export(H_OD_OFF,"H_OD_OFF.txt",1);