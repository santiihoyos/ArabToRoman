#define PROGRAMA    "ArabToRomano"
#define DESCRIPCION "Convierte un número Arabe en Romano"
#define AUTOR   "Santiago Hoyos"
#define VERSION "v0.1 dic/16 CC-BY-NC-SA"
#include"c_facil.h"

//declaración de funciones
NADA construirRomano (NATURAL numero);
NADA descomponerNumero (NATURAL num, NATURAL * unidades, NATURAL * decenas,
			NATURAL * centenas, NATURAL * unisMil);
FRASE
convertir (NATURAL * valorParaConvertir, CARACTER * unos, CARACTER * cincos,
	   CARACTER * exceso);

PRG ()
{
  NATURAL numero = pideNatural ("Escribe un número[1-3999]: ");
  if (siMayorValor (numero, 0))
    {
      //escribeFrase ("El número en romano es= " + escribeFrase ("MMMCMXCIX"));
      construirRomano (numero);
    }
  else
    {
      escribeFrase ("¡El número introducido no es válido!");
    }
}

NADA
construirRomano (NATURAL numero)
{
  FRASE romano = "";

  NATURAL unidades = 0;
  NATURAL decenas = 0;
  NATURAL centenas = 0;
  NATURAL unisMil = 0;

  descomponerNumero (numero, &unidades, &decenas, &centenas, &unisMil);

  escribeFrase ("\n");
  escribeFrase ("Unidades= ");
  escribeNaturalB10 (unidades);
  escribeFrase ("\n");
  escribeFrase ("Decenas= ");
  escribeNaturalB10 (decenas);
  escribeFrase ("\n");
  escribeFrase ("Centenas= ");
  escribeNaturalB10 (centenas);
  escribeFrase ("\n");
  escribeFrase ("Unidades de mil= ");
  escribeNaturalB10 (unisMil);

  escribeFrase ("\n");
  escribeFrase ("\n");
  escribeFrase ("\n");
  escribeFrase ("\n");

  CARACTER uno_unis = 'I';

  escribeFrase ("\nconvirtiendo...\n");

  //unidades a romano
  CARACTER unos = 'I';
  CARACTER cincos = 'V';
  CARACTER exceso = 'X';
  FRASE unisEnRomano = convertir (&unidades, &unos, &cincos, &exceso);

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
  *unidades = restoEnteros (num, 10);
  num = cocienteEnteros ((restaNumeros (num, *unidades)), 10);
  *decenas = restoEnteros (num, 10);
  num = cocienteEnteros ((restaNumeros (num, *decenas)), 10);
  *centenas = restoEnteros (num, 10);
  num = cocienteEnteros ((restaNumeros (num, *centenas)), 10);
  *unisMil = restoEnteros (num, 10);
}

/*
*
*/
FRASE
convertir (NATURAL * valorParaConvertir, CARACTER * unos, CARACTER * cincos,
	   CARACTER * exceso)
{

  FRASE respuesta = "";

  switch (*valorParaConvertir)
    {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    }

  return respuesta;
}
