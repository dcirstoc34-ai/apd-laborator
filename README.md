# APD - Laborator

Proiect de laborator pentru disciplina Achiziția și prelucrarea datelor.
Nod de achiziție a temperaturii bazat pe Arduino Uno.

## Autor
Cîrstoc Darius Ionuț - Grupa TI

## Hardware
Arduino Uno R3, senzor de temperatură TMP36

## Note
Parolele și cheile de acces nu se stochează în git pentru a preveni scurgerile de securitate.

## Parametri de sistem
- Perioada de eșantionare: 500 ms
- Status LED: GPIO 2

## Senzori utilizați
| Senzor | Interfață | Domeniu |
|---|---|---|
| TMP36 | Analogic (A0) | -40°C +125°C |s

## Notițe Proiect
- Frecvența de eșantionare recomandată este de 100 ms.
- Toate datele citite vor fi salvate local înainte de procesare.
