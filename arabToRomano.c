#define PROGRAMA    "ArabToRoman"
#define DESCRIPCION "Convierte un número Arabe en Romano"
#define AUTOR   "Santiago Hoyos"
#define VERSION "v0.1 dic/16 CC-BY-NC-SA"
#include"c_facil.h"

/*
* He querido ser lo mas fidedigno al programa en blocky donde ha usado pasos por refenrencias
* es lo unico que no he podido hacer sin hacer uso de C base.
*/

//declaración de funciones
NADA pintarRomano (NATURAL numero);
NADA descomponerNumero (NATURAL num, NATURAL * unidades, NATURAL * decenas,
			NATURAL * centenas, NATURAL * unisMil);
NADA
convertir (NATURAL valorParaConvertir, CARACTER unos, CARACTER cincos,
	   CARACTER exceso);

PRG ()
{
  NATURAL numero;
  asignaValorA (numero, pideNatural ("Escribe un número[1-3999]: "));

  //se podría desanidar un if usando un &&
  if (siMayorValor (numero, 0))
    {
      if (siMenorIgualValor (numero, 3999))
	{
	  pintarRomano (numero);
	}
    }
  else
    {
      escribeFrase ("\n¡El número introducido no es válido!\n");
    }
}


/*
* Función que llama a las funciones pertinenter para pintar el romano en la salida estandar
*/
NADA
pintarRomano (NATURAL numero)
{

  NATURAL unidades, decenas, centenas, unisMil;

  //llamada a descomposición del numéro haciendo paso por referencia como en el blocky
  descomponerNumero (numero, &unidades, &decenas, &centenas, &unisMil);

  /*PINTADO DEL RESULTADO: 
   * me gustaria poder almacenar el romano en una cadena y concatenar el resultado.
   */
  escribeFrase ("el número ");
  escribeNatural (numero);
  escribeFrase (" en romano es el=  ");

  //unidades de mil
  convertir (unisMil, 'M', '_', '_');

  //centenas
  convertir (centenas, 'C', 'D', 'M');

  //decenas
  convertir (decenas, 'X', 'L', 'C');

  //unidades a romano
  convertir (unidades, 'I', 'V', 'X');

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
convertir (NATURAL valorParaConvertir, CARACTER unos, CARACTER cincos,
	   CARACTER exceso)
{
  //he usado un else if para no usar switch y mantenernos en la linea de clase
  if (siMayorValor (valorParaConvertir, 0))
    {
      if (siIgualValor (valorParaConvertir, 1))
	{
	  escribeCaracter (unos);
	}
      else if (siIgualValor (valorParaConvertir, 2))
	{
	  escribeCaracter (unos);
	  escribeCaracter (unos);
	}
      else if (siIgualValor (valorParaConvertir, 3))
	{
	  escribeCaracter (unos);
	  escribeCaracter (unos);
	  escribeCaracter (unos);
	}
      else if (siIgualValor (valorParaConvertir, 4))
	{
	  escribeCaracter (unos);
	  escribeCaracter (cincos);
	}
      else if (siIgualValor (valorParaConvertir, 5))
	{
	  escribeCaracter (cincos);
	}
      else if (siIgualValor (valorParaConvertir, 6))
	{
	  escribeCaracter (cincos);
	  escribeCaracter (unos);
	}
      else if (siIgualValor (valorParaConvertir, 7))
	{
	  escribeCaracter (cincos);
	  escribeCaracter (unos);
	  escribeCaracter (unos);
	}
      else if (siIgualValor (valorParaConvertir, 8))
	{
	  escribeCaracter (cincos);
	  escribeCaracter (unos);
	  escribeCaracter (unos);
	  escribeCaracter (unos);
	}
      else if (siIgualValor (valorParaConvertir, 9))
	{
	  escribeCaracter (unos);
	  escribeCaracter (exceso);
	}
    }
}