new;
chdir C:\EnvCan\Windsor\ODs\2006\cvwkday\results;

z=70;

load LOD4[z,z]=LC_Tij_4.txt ;
load LOD5[z,z]=LC_Tij_5.txt ;
load LOD6[z,z]=LC_Tij_6.txt ;
load LOD7[z,z]=LC_Tij_7.txt ;
load LOD8[z,z]=LC_Tij_8.txt ;
load LOD9[z,z]=LC_Tij_9.txt ;
load LOD10[z,z]=LC_Tij_10.txt ;
load LOD11[z,z]=LC_Tij_11.txt ;
load LOD12[z,z]=LC_Tij_12.txt ;
load LOD13[z,z]=LC_Tij_13.txt ;
load LOD14[z,z]=LC_Tij_14.txt ;
load LOD15[z,z]=LC_Tij_15.txt ;
load LOD16[z,z]=LC_Tij_16.txt ;
load LOD17[z,z]=LC_Tij_17.txt ;
load LOD18[z,z]=LC_Tij_18.txt ;
load LOD19[z,z]=LC_Tij_19.txt ;
load LOD20[z,z]=LC_Tij_20.txt ;
load LOD21[z,z]=LC_Tij_21.txt ;
load LOD22[z,z]=LC_Tij_22.txt ;
load LOD23[z,z]=LC_Tij_23.txt ;
load LOD24[z,z]=LC_Tij_24.txt ;
load LOD25[z,z]=LC_Tij_25.txt ;
load LOD26[z,z]=LC_Tij_26.txt ;
load LOD27[z,z]=LC_Tij_27.txt ;


RZ=zeros(14,70);
CZ=zeros(84,14);

L4=LOD4|RZ;
L4n=L4~CZ;
L5=LOD5|RZ;
L5n=L5~CZ;
L6=LOD6|RZ;
L6n=L6~CZ;
L7=LOD7|RZ;
L7n=L7~CZ;
L8=LOD8|RZ;
L8n=L8~CZ;
L9=LOD9|RZ;
L9n=L9~CZ;
L10=LOD10|RZ;
L10n=L10~CZ;
L11=LOD11|RZ;
L11n=L11~CZ;
L12=LOD12|RZ;
L12n=L12~CZ;
L13=LOD13|RZ;
L13n=L13~CZ;
L14=LOD14|RZ;
L14n=L14~CZ;
L15=LOD15|RZ;
L15n=L15~CZ;
L16=LOD16|RZ;
L16n=L16~CZ;
L17=LOD17|RZ;
L17n=L17~CZ;
L18=LOD18|RZ;
L18n=L18~CZ;
L19=LOD19|RZ;
L19n=L19~CZ;
L20=LOD20|RZ;
L20n=L20~CZ;
L21=LOD21|RZ;
L21n=L21~CZ;
L22=LOD22|RZ;
L22n=L22~CZ;
L23=LOD23|RZ;
L23n=L23~CZ;
L24=LOD24|RZ;
L24n=L24~CZ;
L25=LOD25|RZ;
L25n=L25~CZ;
L26=LOD26|RZ;
L26n=L26~CZ;
L27=LOD27|RZ;
L27n=L27~CZ;

export(L4n,"LC_Nij_4.txt",1);
export(L5n,"LC_Nij_5.txt",1);
export(L6n,"LC_Nij_6.txt",1);
export(L7n,"LC_Nij_7.txt",1);
export(L8n,"LC_Nij_8.txt",1);
export(L9n,"LC_Nij_9.txt",1);
export(L10n,"LC_Nij_10.txt",1);
export(L11n,"LC_Nij_11.txt",1);
export(L12n,"LC_Nij_12.txt",1);
export(L13n,"LC_Nij_13.txt",1);
export(L14n,"LC_Nij_14.txt",1);
export(L15n,"LC_Nij_15.txt",1);
export(L16n,"LC_Nij_16.txt",1);
export(L17n,"LC_Nij_17.txt",1);
export(L18n,"LC_Nij_18.txt",1);
export(L19n,"LC_Nij_19.txt",1);
export(L20n,"LC_Nij_20.txt",1);
export(L21n,"LC_Nij_21.txt",1);
export(L22n,"LC_Nij_22.txt",1);
export(L23n,"LC_Nij_23.txt",1);
export(L24n,"LC_Nij_24.txt",1);
export(L25n,"LC_Nij_25.txt",1);
export(L26n,"LC_Nij_26.txt",1);
export(L27n,"LC_Nij_27.txt",1);



load MOD4[z,z]=MC_Tij_4.txt ;
load MOD5[z,z]=MC_Tij_5.txt ;
load MOD6[z,z]=MC_Tij_6.txt ;
load MOD7[z,z]=MC_Tij_7.txt ;
load MOD8[z,z]=MC_Tij_8.txt ;
load MOD9[z,z]=MC_Tij_9.txt ;
load MOD10[z,z]=MC_Tij_10.txt ;
load MOD11[z,z]=MC_Tij_11.txt ;
load MOD12[z,z]=MC_Tij_12.txt ;
load MOD13[z,z]=MC_Tij_13.txt ;
load MOD14[z,z]=MC_Tij_14.txt ;
load MOD15[z,z]=MC_Tij_15.txt ;
load MOD16[z,z]=MC_Tij_16.txt ;
load MOD17[z,z]=MC_Tij_17.txt ;
load MOD18[z,z]=MC_Tij_18.txt ;
load MOD19[z,z]=MC_Tij_19.txt ;
load MOD20[z,z]=MC_Tij_20.txt ;
load MOD21[z,z]=MC_Tij_21.txt ;
load MOD22[z,z]=MC_Tij_22.txt ;
load MOD23[z,z]=MC_Tij_23.txt ;
load MOD24[z,z]=MC_Tij_24.txt ;
load MOD25[z,z]=MC_Tij_25.txt ;
load MOD26[z,z]=MC_Tij_26.txt ;
load MOD27[z,z]=MC_Tij_27.txt ;






M4=MOD4|RZ;
M4n=M4~CZ;
M5=MOD5|RZ;
M5n=M5~CZ;
M6=MOD6|RZ;
M6n=M6~CZ;
M7=MOD7|RZ;
M7n=M7~CZ;
M8=MOD8|RZ;
M8n=M8~CZ;
M9=MOD9|RZ;
M9n=M9~CZ;
M10=MOD10|RZ;
M10n=M10~CZ;
M11=MOD11|RZ;
M11n=M11~CZ;
M12=MOD12|RZ;
M12n=M12~CZ;
M13=MOD13|RZ;
M13n=M13~CZ;
M14=MOD14|RZ;
M14n=M14~CZ;
M15=MOD15|RZ;
M15n=M15~CZ;
M16=MOD16|RZ;
M16n=M16~CZ;
M17=MOD17|RZ;
M17n=M17~CZ;
M18=MOD18|RZ;
M18n=M18~CZ;
M19=MOD19|RZ;
M19n=M19~CZ;
M20=MOD20|RZ;
M20n=M20~CZ;
M21=MOD21|RZ;
M21n=M21~CZ;
M22=MOD22|RZ;
M22n=M22~CZ;
M23=MOD23|RZ;
M23n=M23~CZ;
M24=MOD24|RZ;
M24n=M24~CZ;
M25=MOD25|RZ;
M25n=M25~CZ;
M26=MOD26|RZ;
M26n=M26~CZ;
M27=MOD27|RZ;
M27n=M27~CZ;

export(M4n,"MC_Nij_4.txt",1);
export(M5n,"MC_Nij_5.txt",1);
export(M6n,"MC_Nij_6.txt",1);
export(M7n,"MC_Nij_7.txt",1);
export(M8n,"MC_Nij_8.txt",1);
export(M9n,"MC_Nij_9.txt",1);
export(M10n,"MC_Nij_10.txt",1);
export(M11n,"MC_Nij_11.txt",1);
export(M12n,"MC_Nij_12.txt",1);
export(M13n,"MC_Nij_13.txt",1);
export(M14n,"MC_Nij_14.txt",1);
export(M15n,"MC_Nij_15.txt",1);
export(M16n,"MC_Nij_16.txt",1);
export(M17n,"MC_Nij_17.txt",1);
export(M18n,"MC_Nij_18.txt",1);
export(M19n,"MC_Nij_19.txt",1);
export(M20n,"MC_Nij_20.txt",1);
export(M21n,"MC_Nij_21.txt",1);
export(M22n,"MC_Nij_22.txt",1);
export(M23n,"MC_Nij_23.txt",1);
export(M24n,"MC_Nij_24.txt",1);
export(M25n,"MC_Nij_25.txt",1);
export(M26n,"MC_Nij_26.txt",1);
export(M27n,"MC_Nij_27.txt",1);


load HOD4[z,z]=HC_Tij_4.txt ;
load HOD5[z,z]=HC_Tij_5.txt ;
load HOD6[z,z]=HC_Tij_6.txt ;
load HOD7[z,z]=HC_Tij_7.txt ;
load HOD8[z,z]=HC_Tij_8.txt ;
load HOD9[z,z]=HC_Tij_9.txt ;
load HOD10[z,z]=HC_Tij_10.txt ;
load HOD11[z,z]=HC_Tij_11.txt ;
load HOD12[z,z]=HC_Tij_12.txt ;
load HOD13[z,z]=HC_Tij_13.txt ;
load HOD14[z,z]=HC_Tij_14.txt ;
load HOD15[z,z]=HC_Tij_15.txt ;
load HOD16[z,z]=HC_Tij_16.txt ;
load HOD17[z,z]=HC_Tij_17.txt ;
load HOD18[z,z]=HC_Tij_18.txt ;
load HOD19[z,z]=HC_Tij_19.txt ;
load HOD20[z,z]=HC_Tij_20.txt ;
load HOD21[z,z]=HC_Tij_21.txt ;
load HOD22[z,z]=HC_Tij_22.txt ;
load HOD23[z,z]=HC_Tij_23.txt ;
load HOD24[z,z]=HC_Tij_24.txt ;
load HOD25[z,z]=HC_Tij_25.txt ;
load HOD26[z,z]=HC_Tij_26.txt ;
load HOD27[z,z]=HC_Tij_27.txt ;






H4=HOD4|RZ;
H4n=H4~CZ;
H5=HOD5|RZ;
H5n=H5~CZ;
H6=HOD6|RZ;
H6n=H6~CZ;
H7=HOD7|RZ;
H7n=H7~CZ;
H8=HOD8|RZ;
H8n=H8~CZ;
H9=HOD9|RZ;
H9n=H9~CZ;
H10=HOD10|RZ;
H10n=H10~CZ;
H11=HOD11|RZ;
H11n=H11~CZ;
H12=HOD12|RZ;
H12n=H12~CZ;
H13=HOD13|RZ;
H13n=H13~CZ;
H14=HOD14|RZ;
H14n=H14~CZ;
H15=HOD15|RZ;
H15n=H15~CZ;
H16=HOD16|RZ;
H16n=H16~CZ;
H17=HOD17|RZ;
H17n=H17~CZ;
H18=HOD18|RZ;
H18n=H18~CZ;
H19=HOD19|RZ;
H19n=H19~CZ;
H20=HOD20|RZ;
H20n=H20~CZ;
H21=HOD21|RZ;
H21n=H21~CZ;
H22=HOD22|RZ;
H22n=H22~CZ;
H23=HOD23|RZ;
H23n=H23~CZ;
H24=HOD24|RZ;
H24n=H24~CZ;
H25=HOD25|RZ;
H25n=H25~CZ;
H26=HOD26|RZ;
H26n=H26~CZ;
H27=HOD27|RZ;
H27n=H27~CZ;

export(H4n,"HC_Nij_4.txt",1);
export(H5n,"HC_Nij_5.txt",1);
export(H6n,"HC_Nij_6.txt",1);
export(H7n,"HC_Nij_7.txt",1);
export(H8n,"HC_Nij_8.txt",1);
export(H9n,"HC_Nij_9.txt",1);
export(H10n,"HC_Nij_10.txt",1);
export(H11n,"HC_Nij_11.txt",1);
export(H12n,"HC_Nij_12.txt",1);
export(H13n,"HC_Nij_13.txt",1);
export(H14n,"HC_Nij_14.txt",1);
export(H15n,"HC_Nij_15.txt",1);
export(H16n,"HC_Nij_16.txt",1);
export(H17n,"HC_Nij_17.txt",1);
export(H18n,"HC_Nij_18.txt",1);
export(H19n,"HC_Nij_19.txt",1);
export(H20n,"HC_Nij_20.txt",1);
export(H21n,"HC_Nij_21.txt",1);
export(H22n,"HC_Nij_22.txt",1);
export(H23n,"HC_Nij_23.txt",1);
export(H24n,"HC_Nij_24.txt",1);
export(H25n,"HC_Nij_25.txt",1);
export(H26n,"HC_Nij_26.txt",1);
export(H27n,"HC_Nij_27.txt",1);