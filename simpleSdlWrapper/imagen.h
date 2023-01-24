#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 10

//Irudi bakoitzaren ID-a
#define ARRAIN_GIZON_ID 1

int irudiaKargatu(char* fileName, int id);
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
void irudiaKendu(int id);

#endif
