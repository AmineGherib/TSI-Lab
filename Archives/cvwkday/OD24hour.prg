new;
z=70;
chdir C:\EnvCan\Windsor\ODs\2006\cvwkday;
load L_OD_AM[z,z]=L_OD_AM.txt;
load L_OD_PM[z,z]=L_OD_PM.txt;
load L_OD_OF[z,z]=L_OD_OFF.txt;

load M_OD_AM[z,z]=M_OD_AM.txt;
load M_OD_PM[z,z]=M_OD_PM.txt;
load M_OD_OF[z,z]=M_OD_OFF.txt;

load H_OD_AM[z,z]=H_OD_AM.txt;
load H_OD_PM[z,z]=H_OD_PM.txt;
load H_OD_OF[z,z]=H_OD_OFF.txt;


load prop24[24,3]=Prop24hours.txt;


/*calculating Light commerical OD's 24 hours*/

LOD0 = prop24[1,1] .* L_OD_OF;
LOD1 = prop24[2,1] .* L_OD_OF;
LOD2 = prop24[3,1] .* L_OD_OF;
LOD3 = prop24[4,1] .* L_OD_OF;
LOD4 = prop24[5,1] .* L_OD_OF;
LOD5 = prop24[6,1] .* L_OD_OF;
LOD6 = prop24[7,1] .* L_OD_AM;
LOD7 = prop24[8,1] .* L_OD_AM;
LOD8 = prop24[9,1] .* L_OD_AM;
LOD9 = prop24[10,1] .* L_OD_OF;
LOD10 = prop24[11,1] .* L_OD_OF;
LOD11 = prop24[12,1] .* L_OD_OF;
LOD12 = prop24[13,1] .* L_OD_OF;
LOD13 = prop24[14,1] .* L_OD_OF;
LOD14 = prop24[15,1] .* L_OD_OF;
LOD15 = prop24[16,1] .* L_OD_OF;
LOD16 = prop24[17,1] .* L_OD_PM;
LOD17 = prop24[18,1] .* L_OD_PM;
LOD18 = prop24[19,1] .* L_OD_PM;
LOD19 = prop24[20,1] .* L_OD_OF;
LOD20 = prop24[21,1] .* L_OD_OF;
LOD21 = prop24[22,1] .* L_OD_OF;
LOD22 = prop24[23,1] .* L_OD_OF;
LOD23 = prop24[24,1] .* L_OD_OF;

/*calculating medium commerical OD's 24 hours*/

MOD0 = prop24[1,2] .* M_OD_OF;
MOD1 = prop24[2,2] .* M_OD_OF;
MOD2 = prop24[3,2] .* M_OD_OF;
MOD3 = prop24[4,2] .* M_OD_OF;
MOD4 = prop24[5,2] .* M_OD_OF;
MOD5 = prop24[6,2] .* M_OD_OF;
MOD6 = prop24[7,2] .* M_OD_AM;
MOD7 = prop24[8,2] .* M_OD_AM;
MOD8 = prop24[9,2] .* M_OD_AM;
MOD9 = prop24[10,2] .* M_OD_OF;
MOD10 = prop24[11,2] .* M_OD_OF;
MOD11 = prop24[12,2] .* M_OD_OF;
MOD12 = prop24[13,2] .* M_OD_OF;
MOD13 = prop24[14,2] .* M_OD_OF;
MOD14 = prop24[15,2] .* M_OD_OF;
MOD15 = prop24[16,2] .* M_OD_OF;
MOD16 = prop24[17,2] .* M_OD_PM;
MOD17 = prop24[18,2] .* M_OD_PM;
MOD18 = prop24[19,2] .* M_OD_PM;
MOD19 = prop24[20,2] .* M_OD_OF;
MOD20 = prop24[21,2] .* M_OD_OF;
MOD21 = prop24[22,2] .* M_OD_OF;
MOD22 = prop24[23,2] .* M_OD_OF;
MOD23 = prop24[24,2] .* M_OD_OF;

/*calculating medium commerical OD's 24 hours*/

HOD0 = prop24[1,3] .* H_OD_OF;
HOD1 = prop24[2,3] .* H_OD_OF;
HOD2 = prop24[3,3] .* H_OD_OF;
HOD3 = prop24[4,3] .* H_OD_OF;
HOD4 = prop24[5,3] .* H_OD_OF;
HOD5 = prop24[6,3] .* H_OD_OF;
HOD6 = prop24[7,3] .* H_OD_AM;
HOD7 = prop24[8,3] .* H_OD_AM;
HOD8 = prop24[9,3] .* H_OD_AM;
HOD9 = prop24[10,3] .* H_OD_OF;
HOD10 = prop24[11,3] .* H_OD_OF;
HOD11 = prop24[12,3] .* H_OD_OF;
HOD12 = prop24[13,3] .* H_OD_OF;
HOD13 = prop24[14,3] .* H_OD_OF;
HOD14 = prop24[15,3] .* H_OD_OF;
HOD15 = prop24[16,3] .* H_OD_OF;
HOD16 = prop24[17,3] .* H_OD_PM;
HOD17 = prop24[18,3] .* H_OD_PM;
HOD18 = prop24[19,3] .* H_OD_PM;
HOD19 = prop24[20,3] .* H_OD_OF;
HOD20 = prop24[21,3] .* H_OD_OF;
HOD21 = prop24[22,3] .* H_OD_OF;
HOD22 = prop24[23,3] .* H_OD_OF;
HOD23 = prop24[24,3] .* H_OD_OF;

/*Calculate Summary from the Tabs - Total trips by type and hour of day*/

sumc(sumc(LOD0 ));
sumc(sumc(LOD1 ));
sumc(sumc(LOD2 ));
sumc(sumc(LOD3 ));
sumc(sumc(LOD4 ));
sumc(sumc(LOD5 ));
sumc(sumc(LOD6 ));
sumc(sumc(LOD7 ));
sumc(sumc(LOD8 ));
sumc(sumc(LOD9 ));
sumc(sumc(LOD10));
sumc(sumc(LOD11));
sumc(sumc(LOD12));
sumc(sumc(LOD13));
sumc(sumc(LOD14));
sumc(sumc(LOD15));
sumc(sumc(LOD16));
sumc(sumc(LOD17));
sumc(sumc(LOD18));
sumc(sumc(LOD19));
sumc(sumc(LOD20));
sumc(sumc(LOD21));
sumc(sumc(LOD22));
sumc(sumc(LOD23));

/*calculating medium commerical OD's 24 hours*/

sumc(sumc(MOD0 ));
sumc(sumc(MOD1 ));
sumc(sumc(MOD2 ));
sumc(sumc(MOD3 ));
sumc(sumc(MOD4 ));
sumc(sumc(MOD5 ));
sumc(sumc(MOD6 ));
sumc(sumc(MOD7 ));
sumc(sumc(MOD8 ));
sumc(sumc(MOD9 ));
sumc(sumc(MOD10 ));
sumc(sumc(MOD11 ));
sumc(sumc(MOD12 ));
sumc(sumc(MOD13 ));
sumc(sumc(MOD14 ));
sumc(sumc(MOD15 ));
sumc(sumc(MOD16 ));
sumc(sumc(MOD17 ));
sumc(sumc(MOD18 ));
sumc(sumc(MOD19 ));
sumc(sumc(MOD20 ));
sumc(sumc(MOD21 ));
sumc(sumc(MOD22 ));
sumc(sumc(MOD23 ));

/*calculating medium commerical OD's 24 hours*/

sumc(sumc(HOD0 ));
sumc(sumc(HOD1 ));
sumc(sumc(HOD2 ));
sumc(sumc(HOD3 ));
sumc(sumc(HOD4 ));
sumc(sumc(HOD5 ));
sumc(sumc(HOD6 ));
sumc(sumc(HOD7 ));
sumc(sumc(HOD8 ));
sumc(sumc(HOD9 ));
sumc(sumc(HOD10 ));
sumc(sumc(HOD11 ));
sumc(sumc(HOD12 ));
sumc(sumc(HOD13 ));
sumc(sumc(HOD14 ));
sumc(sumc(HOD15 ));
sumc(sumc(HOD16 ));
sumc(sumc(HOD17 ));
sumc(sumc(HOD18 ));
sumc(sumc(HOD19 ));
sumc(sumc(HOD20 ));
sumc(sumc(HOD21 ));
sumc(sumc(HOD22 ));
sumc(sumc(HOD23 ));

chdir C:\EnvCan\Windsor\ODs\2006\cvwkday\results;

export(LOD0,"LC_Tij_24.txt",1 );
export(LOD1 ,"LC_Tij_25.txt",1);
export(LOD2 ,"LC_Tij_26.txt",1);
export(LOD3 ,"LC_Tij_27.txt",1);
export(LOD4 ,"LC_Tij_4.txt",1);
export(LOD5 ,"LC_Tij_5.txt",1);
export(LOD6 ,"LC_Tij_6.txt",1);
export(LOD7 ,"LC_Tij_7.txt",1);
export(LOD8 ,"LC_Tij_8.txt",1);
export(LOD9 ,"LC_Tij_9.txt",1);
export(LOD10,"LC_Tij_10.txt",1);
export(LOD11,"LC_Tij_11.txt",1);
export(LOD12,"LC_Tij_12.txt",1);
export(LOD13,"LC_Tij_13.txt",1);
export(LOD14,"LC_Tij_14.txt",1);
export(LOD15,"LC_Tij_15.txt",1);
export(LOD16,"LC_Tij_16.txt",1);
export(LOD17,"LC_Tij_17.txt",1);
export(LOD18,"LC_Tij_18.txt",1);
export(LOD19,"LC_Tij_19.txt",1);
export(LOD20,"LC_Tij_20.txt",1);
export(LOD21,"LC_Tij_21.txt",1);
export(LOD22,"LC_Tij_22.txt",1);
export(LOD23,"LC_Tij_23.txt",1);

/*calculating medium commerical OD's 24 hours*/


export(MOD0,"MC_Tij_24.txt",1 );
export(MOD1 ,"MC_Tij_25.txt",1);
export(MOD2 ,"MC_Tij_26.txt",1);
export(MOD3 ,"MC_Tij_27.txt",1);
export(MOD4 ,"MC_Tij_4.txt",1);
export(MOD5 ,"MC_Tij_5.txt",1);
export(MOD6 ,"MC_Tij_6.txt",1);
export(MOD7 ,"MC_Tij_7.txt",1);
export(MOD8 ,"MC_Tij_8.txt",1);
export(MOD9 ,"MC_Tij_9.txt",1);
export(MOD10,"MC_Tij_10.txt",1);
export(MOD11,"MC_Tij_11.txt",1);
export(MOD12,"MC_Tij_12.txt",1);
export(MOD13,"MC_Tij_13.txt",1);
export(MOD14,"MC_Tij_14.txt",1);
export(MOD15,"MC_Tij_15.txt",1);
export(MOD16,"MC_Tij_16.txt",1);
export(MOD17,"MC_Tij_17.txt",1);
export(MOD18,"MC_Tij_18.txt",1);
export(MOD19,"MC_Tij_19.txt",1);
export(MOD20,"MC_Tij_20.txt",1);
export(MOD21,"MC_Tij_21.txt",1);
export(MOD22,"MC_Tij_22.txt",1);
export(MOD23,"MC_Tij_23.txt",1);

/*calculating medium commerical OD's 24 hours*/


export(HOD0,"HC_Tij_24.txt",1 );
export(HOD1 ,"HC_Tij_25.txt",1);
export(HOD2 ,"HC_Tij_26.txt",1);
export(HOD3 ,"HC_Tij_27.txt",1);
export(HOD4 ,"HC_Tij_4.txt",1);
export(HOD5 ,"HC_Tij_5.txt",1);
export(HOD6 ,"HC_Tij_6.txt",1);
export(HOD7 ,"HC_Tij_7.txt",1);
export(HOD8 ,"HC_Tij_8.txt",1);
export(HOD9 ,"HC_Tij_9.txt",1);
export(HOD10,"HC_Tij_10.txt",1);
export(HOD11,"HC_Tij_11.txt",1);
export(HOD12,"HC_Tij_12.txt",1);
export(HOD13,"HC_Tij_13.txt",1);
export(HOD14,"HC_Tij_14.txt",1);
export(HOD15,"HC_Tij_15.txt",1);
export(HOD16,"HC_Tij_16.txt",1);
export(HOD17,"HC_Tij_17.txt",1);
export(HOD18,"HC_Tij_18.txt",1);
export(HOD19,"HC_Tij_19.txt",1);
export(HOD20,"HC_Tij_20.txt",1);
export(HOD21,"HC_Tij_21.txt",1);
export(HOD22,"HC_Tij_22.txt",1);
export(HOD23,"HC_Tij_23.txt",1);