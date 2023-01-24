#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"
#include "soinua.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct
{
  POSIZIOA pos;
  int id;
  MOTA mota;
}JOKO_ELEMENTUA;

typedef struct S_GURE_GAUZAK
{
	int idSounds[MAX_SOUNDS];
	int idIrudiak;
}GURE_GAUZAK;

#endif