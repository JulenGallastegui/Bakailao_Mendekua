#ifndef MUGIMENDUA_H
#define MUGIMENDUA_H
#include "SDL.h"

//Return esanahiak 0: ez da mugitzeko teklarik jo. 1: mugitu egin da. 2: ez da mmugitu txokatzen dagoelako
int MugituPertsonaia(int ebentu, int zenbat);

//Arrain Gizon koordenada batzuetan kokatzeko lehen frame-ean, eta maparen kolisioak kargatu.
//Return esanahiak 1: Ondo hasieratua. 0: koordenadak pantailatik kanpo daude. -1: maparen izena gaizki dago. -2: sartutako koordenatuak kolisio baten barruan daude.
int MugimenduaHasieratu(int x, int y, char* mapaIzena);

#endif