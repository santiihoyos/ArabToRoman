#define PROGRAMA    "ArabToRoman"
#define DESCRIPCION "Convierte un número Arabe en Romano"
#define AUTOR   "Santiago Hoyos"
#define VERSION "v0.1 dic/16 CC-BY-NC-SA"
#include"c_facil.h"

//declaración de funciones
NADA pintarRomano (NATURAL numero);
NADA descomponerNumero (NATURAL num, NATURAL * unidades, NATURAL * decenas,
			NATURAL * centenas, NATURAL * unisMil);
NADA
convertir (NATURAL * valorParaConvertir, CARACTER unos, CARACTER cincos,
	   CARACTER exceso);

PRG ()
{
  NATURAL numero;
  asignaValorA (numero, pideNatural ("Escribe un número[1-3999]: "));

  if (siMayorValor (numero, 0) && siMenorIgualValor (numero, 3999))
    {
      //escribeFrase ("El número en romano es= " + escribeFrase ("MMMCMXCIX"));
      pintarRomano (numero);
    }
  else
    {
      escribeFrase ("\n¡El número introducido no es válido!\n");
    }
}

NADA
pintarRomano (NATURAL numero)
{

  NATURAL unidades;
  NATURAL decenas;
  NATURAL centenas;
  NATURAL unisMil;
  descomponerNumero (numero, &unidades, &decenas, &centenas, &unisMil);


  /*PINTADO DEL RESULTADO: 
   * me gustaria poder almacenar el romano en una cadena
   * pero con los tipos de datos definidos en c_facil.h no me resulta fácil.
   */
  escribeFrase ("el número ");
  escribeNatural (numero);
  escribeFrase (" en romano es el=  ");

  //unidades de mil
  convertir (&unisMil, 'M', '_', '_');

  //centenas
  convertir (&centenas, 'C', 'D', 'M');

  //decenas
  convertir (&decenas, 'X', 'L', 'C');

  //unidades a romano
  convertir (&unidades, 'I', 'V', 'X');

  escribeFrase ("\n");
}

/*
* Función que recibe el número arabe y los punteros donde colocar las unidades,decenas,centenas
* lo he hecho así para que sea totalmente fidedigno al programa del codeblock qeu pasa por
* referencia.
*/
NADA
descomponerNumero (NATURAL num, NATURAL * unidades, NATURAL * decenas,
		   NATURAL * centenas, NATURAL * unisMil)
{
  asignaValorA (*unidades, restoEnteros (num, 10));
  asignaValorA (num, cocienteEnteros ((restaNumeros (num, *unidades)), 10));
  asignaValorA (*decenas, restoEnteros (num, 10));
  asignaValorA (num, cocienteEnteros ((restaNumeros (num, *decenas)), 10));
  asignaValorA (*centenas, restoEnteros (num, 10));
  asignaValorA (num, cocienteEnteros ((restaNumeros (num, *centenas)), 10));
  asignaValorA (*unisMil, restoEnteros (num, 10));
}


/*
* Dado un número y unos simbolos convierte a romano.
* se le ha de pasar la respresentación de la unidad, la representacion de las 5 unidades y
* la representación de la unidad siguiente.
*/
NADA
convertir (NATURAL * valorParaConvertir, CARACTER unos, CARACTER cincos,
	   CARACTER exceso)
{
  switch (*valorParaConvertir)
    {
    case 0:
      break;
    case 1:
      escribeCaracter (unos);
      break;
    case 2:
      escribeCaracter (unos);
      escribeCaracter (unos);
      break;
    case 3:
      escribeCaracter (unos);
      escribeCaracter (unos);
      escribeCaracter (unos);
      break;
    case 4:
      escribeCaracter (unos);
      escribeCaracter (cincos);
      break;
    case 5:
      escribeCaracter (cincos);
      break;
    case 6:
      escribeCaracter (cincos);
      escribeCaracter (unos);
      break;
    case 7:
      escribeCaracter (cincos);
      escribeCaracter (unos);
      escribeCaracter (unos);
      break;
    case 8:
      escribeCaracter (cincos);
      escribeCaracter (unos);
      escribeCaracter (unos);
      escribeCaracter (unos);
      break;
    case 9:
      escribeCaracter (unos);
      escribeCaracter (exceso);
      break;
    }
}
