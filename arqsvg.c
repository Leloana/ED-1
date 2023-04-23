#include "arqsvg.h"

ArqSvg abreEscritaSvg(char *fn){
    FILE* arquivo = fopen(fn,"w");
    fprintf(arquivo,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg viewBox=\"-110 -110 600 500\" xmlns=\"http://www.w3.org/2000/svg\">");
    return arquivo;
}

void fechaSvg(ArqSvg fsvg){
    fprintf(fsvg,"\n</svg>");
    fclose(fsvg);
}

void escreveCirculoSvg(ArqSvg fsvg,Circulo C){
    fprintf(fsvg,"\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" transform = \"rotate (%lf %lf %lf)\" fill=\"%s\" />",
                                                 get_circ_cx(C), get_circ_cy(C), get_circ_r(C),get_circ_corb(C),get_circ_rot(C),get_circ_cx(C),get_circ_cy(C), get_circ_corp(C));
}