#ifndef ARQSVG__
#define ARQSVG__

#include <stdio.h>
#include <stdlib.h>
#include "Circulo.h"

typedef void* ArqSvg;
// abre arquivo svg e escreve inicio do arquivo
ArqSvg abreEscritaSvg(char *fn);
// escreve fim do arquivo svg e fecha arquivo
void fechaSvg(ArqSvg fsvg);
//escreve o circulo especificado no arquivo svg
void escreveCirculoSvg(ArqSvg,Circulo C);
//escreve o retangulo especificado no arquivo svg
#endif