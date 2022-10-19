#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Programmeeropgave 1: Temperatuur
//Dit is een programma dat bepaalt of de gebruiker geschikt is voor een
//exacte, alpha of geen studie, door vragen te stellen aan de gebruiker.
//Gebruikers onder de 10 en boven de 101 mogen worden verwijderd. Verder
//dienen gebruikers de weekdag van hun geboortedatum te weten.
//
//Datum van aankomst:   26 September 2022
//Onderwijsinrichting:  Universiteit Leiden
//Studie:               Informatica
//Namen:                Sami Fesenko & Jimmy Chao
//studentnummers:       s3587584 & s3495116
//gebruikte editors:    gedit, notepad++, code::blocks
//Gebruikte compiler:   g++, g++ in WSL, code::blocks
//
//betekenissen van returns:
//0: programma beeïndigt zoals het hoort
//1: de ingevoerde waarde geeft aan dat de gebruiker te oud of te jong is
//2: de ingevoerde waarde bestaat niet
//3: de ingevoerde waarde wordt als fout beschouwd door het programma

int main() {

  int dag, maand, jaar; //ctime
  tm s; //ctime
  time_t t; //ctime
  time( & t); //ctime
  s = * localtime( & t); //ctime
  dag = s.tm_mday; //ctime
  maand = s.tm_mon; // 0 voor januari
  jaar = s.tm_year + 1900; // vanaf 1900
  maand = maand + 1; // 1 voor januari
  srand(time(0)); //random number generator

  int birthY, birthM, birthD; // geboortejaar, -maand, -dag
  int ageM, ageY, ageYR; //leefmaanden, leefjaren, rest leefjaren

  int totaalaantaldagen = 0;
  int dagcijfer, dagantwoordcijfer; // 2 voor dinsdag, antwoord voor controle
  char daginput1, daginput2; //input welke dag
  bool net = false; //als true dan nette vragen

  double inputv1 = 0.00, inputv2 = 0.00, antwoordv1 = 0.00, //cin antwoord
    antwoordv2 = 0.00; //antwoorden met 2 decimalen
  int randomgetal = rand() % 161 + (-40); //rand nummer tussen 0-161, daarna -40
  double randomgetaldouble = 0.00; //randnummer in decimalen
  int antwv1int, antwv2int, antwcorrect = 0; //afgerond antwoord

  char mChoiceIn, mChoiceAnsS = 'b', mChoiceAnsL = 'B';
  //meerkeuzevraaginput en antwoorden

  //-----------infoblok-----------
  cout << "Datum van aankomst:	26 September 2022";
  cout << endl << "Onderwijsinrichting:	Universiteit leiden";
  cout << endl << "Studie: 		Informatica";
  cout << endl << "Namen:			Sami Fesenko & Jimmy Chao";
  cout << endl << "studentnummers:	 	s3587584 & s3495116";
  cout << endl << "Programmeeropgave 1:	Temperatuur";
  cout << endl << endl;
  cout << endl << "Welkom, met behulp van dit programma is het mogelijk om een indicatie te krijgen of u";
  cout << endl << "geschikt bent voor een exacte-studie, alpha-studie of geen studie.";
  cout << endl << endl << "Om dit programma te kunnen gebruiken moet u tussen de 10 en 100 jaar oud zijn en moet u de";
  cout << endl << "weekdag van uw geboortedag weten.";
  cout << endl << endl << "De indicatie wordt bepaald door twee exacte vragen, hierbij is het de bedoeling dat u";
  cout << endl << "minimaal een van de twee vragen goed beantwoord. Als het niet lukt om de vragen juist";
  cout << endl << "te beantwoorden, dan zult u een kunstzinnige vraag moeten beantwoorden.";
  cout << endl << endl << "Uit de resultaten van de vragen zal dit programma bepalen welke richting voor u het beste is.";

  //------------bepaling van leeftijd-----------
  cout << endl << endl << "Als eerst hebben wij uw geboortedatum en de weekdag daarvan nodig." << endl;
  cout << endl << "In welk jaar bent u geboren?" << endl << endl;
  cin >> birthY;

  if ((jaar - birthY) < 10 || (jaar - birthY) > 101) {
    cout << endl << "te oud of te jong, programma stopt." << endl << endl;
    return 1; //geeft error als leefjaar onder 10 of boven 100 is
  } else if ((jaar - birthY) > 30) {
	  net = true;
	  cout << endl << "In welke maand bent u geboren?" << endl << endl;
  } else {
	  cout << endl << "In welke maand ben je geboren?" << endl << endl;
  }
  cin >> birthM;
  ageM = ((jaar * 12) + maand) - ((birthY * 12) + birthM); //leeftijd in volledige maanden

  if (birthM > 12 || birthM < 1) {
    cout << endl << "Maand bestaat niet, programma stopt." << endl << endl;
    return 2;
  }
  if (ageM < 120 || ageM > 1212) {
    cout << endl << "Te oud of te jong, programma stopt." << endl << endl;
    return 1;
  } else if (ageM > 360) {
	  net = true;
      cout << endl << "Op welke dag bent u geboren?" << endl << endl;
  } else {
      cout << endl << "Op welke dag ben je geboren?" << endl << endl;
  }
  cin >> birthD;

  if ((birthM == 1 && birthD > 31) || (birthM == 3 && birthD > 31) ||
    (birthM == 4 && birthD > 30) || (birthM == 5 && birthD > 31) ||
    (birthM == 6 && birthD > 30) || (birthM == 7 && birthD > 31) ||
    (birthM == 8 && birthD > 31) || (birthM == 9 && birthD > 30) ||
    (birthM == 10 && birthD > 31) || (birthM == 11 && birthD > 30) ||
    (birthM == 12 && birthD > 31) || birthD < 1) {
    cout << endl << "dag bestaat niet, programma stopt." << endl;
    return 2;
  }

  if (birthM == 2) {
    if (birthY % 4 == 0) {  //checkt of het een schrikkeljaar is
      if (birthD > 29) {
        cout << endl << "dag bestaat niet, programma stopt." << endl;
        return 2;
      }
    } else if (birthD > 28) {
      cout << endl << "dag bestaat niet, programma stopt." << endl;
      return 2;
    }
  }

  if (dag < birthD) {
    ageM = ageM - 1; //haalt een maand eraf als persoon nog niet jarig is geweest
    if(ageM < 120 || ageM > 1212) {
      cout << endl << "te oud of te jong, programma stopt." << endl << endl;
      return 1; //geeft error als leefjaar onder 10 of boven 100 is
	}
  }
  ageY = ageM / 12; //berekening leeftijd in jaren
  ageYR = ageM % 12;  //resterende maanden die niet een volledig jaar vormen

  if ((jaar - birthY == 10 && ageM == 120 && birthD > dag) ||
    (jaar - birthY == 101 && ageM == 1212 && birthD <= dag)) {
    cout << endl << "te jong of te oud, programma stopt." << endl << endl;
    return 1;
  } else if (net == true) {
    cout << endl << "Uw leeftijd is:" << endl;
    cout << ageY << " jaar en " << ageYR << " maanden" <<
      endl << ageM << " maanden" << endl << endl;
  } else {
    cout << endl << "Jouw leeftijd is:" << endl;
    cout << ageY << " jaar en " << ageYR << " maanden" <<
      endl << ageM << " maanden" << endl << endl;
  }

  if (birthM == maand && birthD == dag) { //Jarige en maandige feliciteren
    cout << endl << "Gefeliciteerd! Er is een jarige!" << endl << endl;
  } else if (birthD == dag) {
    cout << endl << "Gefeliciteerd! Er is een maandige!" << endl << endl;
  }

//-----------bepaling van dag-----------
  totaalaantaldagen = (birthY - 1901) * 365 + (birthY - 1901) / 4;
  // aantal dagen tussen geboortejaar en 1901 berekenen + schrikkeljaren

  if (birthM > 1) {  //maanden naar dagen berekenen
    totaalaantaldagen = totaalaantaldagen + 31;
  }
  if (birthM > 2) {
    if (birthY % 4 == 0) {
      totaalaantaldagen = totaalaantaldagen + 29;
    } else {
      totaalaantaldagen = totaalaantaldagen + 28;
    }
  }
  if (birthM > 3) {
    totaalaantaldagen = totaalaantaldagen + 31;
  }
  if (birthM > 4) {
    totaalaantaldagen = totaalaantaldagen + 30;
  }
  if (birthM > 5) {
    totaalaantaldagen = totaalaantaldagen + 31;
  }
  if (birthM > 6) {
    totaalaantaldagen = totaalaantaldagen + 30;
  }
  if (birthM > 7) {
    totaalaantaldagen = totaalaantaldagen + 31;
  }
  if (birthM > 8) {
    totaalaantaldagen = totaalaantaldagen + 31;
  }
  if (birthM > 9) {
    totaalaantaldagen = totaalaantaldagen + 30;
  }
  if (birthM > 10) {
    totaalaantaldagen = totaalaantaldagen + 31;
  }
  if (birthM > 11) {
    totaalaantaldagen = totaalaantaldagen + 30;
  }

  totaalaantaldagen = totaalaantaldagen + birthD;  //neemt de geboortedag mee
  dagcijfer = totaalaantaldagen % 7;  //365%7 is 2 en valt op een dinsdag, dus 3wo etc...

  if (net == true) {
	  cout << endl << "op welke dag(maandag,dinsdag,..) bent u geboren?" <<
	  endl << "geef antwoord met de eerste letter van de dag(m,d,...)" <<
      endl;
  } else {
	  cout << endl << "op welke dag(maandag,dinsdag,..) ben je geboren?" <<
	  endl << "geef antwoord met de eerste letter van de dag(m,d,...)" <<
      endl;
  }

  cin >> daginput1;

  if (daginput1 == 'd' || daginput1 == 'z' || daginput1 == 'D' ||
    daginput1 == 'Z') { //voor input van letters 'd' of 'z' van dagbepaling
    cout << endl << "geef nu de tweede letter van de dag" << endl;
    cin >> daginput2;

    if ((daginput1 == 'd' && daginput2 == 'i') ||
      (daginput1 == 'D' && daginput2 == 'i') ||
      (daginput1 == 'd' && daginput2 == 'I') ||
      (daginput1 == 'D' && daginput2 == 'I')) {
      dagantwoordcijfer = 1; //dinsdag heeft de waarde 1
    } else if ((daginput1 == 'd' && daginput2 == 'o') ||
      (daginput1 == 'D' && daginput2 == 'o') ||
      (daginput1 == 'd' && daginput2 == 'O') ||
      (daginput1 == 'D' && daginput2 == 'O')) {
      dagantwoordcijfer = 3; //donderdag heeft de waarde 3
    } else if ((daginput1 == 'z' && daginput2 == 'a') ||
      (daginput1 == 'Z' && daginput2 == 'a') ||
      (daginput1 == 'z' && daginput2 == 'A') ||
      (daginput1 == 'Z' && daginput2 == 'A')) {
      dagantwoordcijfer = 5; //zaterdag heeft de waarde 5
    } else if ((daginput1 == 'z' && daginput2 == 'o') ||
      (daginput1 == 'Z' && daginput2 == 'o') ||
      (daginput1 == 'z' && daginput2 == 'O') ||
      (daginput1 == 'Z' && daginput2 == 'O')) {
      dagantwoordcijfer = 6; //zondag heeft de waarde 6
    } else {
      cout << endl << "dag bestaat niet, programma stopt." << endl;
      return 2;
    }
  } else if (daginput1 == 'm' || daginput1 == 'M') {
    dagantwoordcijfer = 0; //maandag heeft de waarde 0
  } else if (daginput1 == 'w' || daginput1 == 'W') {
    dagantwoordcijfer = 2; //woensdag heeft de waarde 2
  } else if (daginput1 == 'v' || daginput1 == 'V') {
    dagantwoordcijfer = 4; //vrijdag heeft de waarde 4
  } else {
    cout << endl << "dag bestaat niet, programma stopt." << endl;
    return 2;
  }

  if (dagantwoordcijfer == dagcijfer) { //controle voor het antwoord van de dagen
    cout << endl << "Dat is correct! Nu begint de test." << endl;
  } else {
    cout << endl << "dag is fout, programma stopt." << endl;
    return 3;
  };

  //-----------vraag 1a-----------
  randomgetaldouble = randomgetal;
  antwoordv1 = (randomgetaldouble - 32) * 5 / 9; //formule voor omzetten naar celsius

  cout << endl << "vraag 1a" << endl << endl;
  cout << endl << "zet de volgende temperatuur van graden Fahrenheit om in graden Celsius." << endl;
  cout << "Geef antwoord in hele getallen." << endl;
  cout << endl << randomgetal << endl;
  cin >> inputv1;

  if (antwoordv1 < 0) { //afronding
    antwoordv1 = antwoordv1 - 0.5;
  } else {
    antwoordv1 = antwoordv1 + 0.5;
  }

  antwv1int = antwoordv1;

  if (inputv1 == antwv1int || inputv1 == antwv1int - 1 ||
    inputv1 == antwv1int + 1) {  //checkt of het input een goed antwoord was
    cout << endl << "correct, het antwoord was " << antwv1int << "." << endl;
    antwcorrect++;
  } else {
    cout << endl << "incorrect, het juiste antwoord was " <<
      antwv1int << "." << endl;
  }

//-----------1b-----------
  antwoordv2 = (randomgetaldouble * 9 / 5) + 32; //formule van celsius naar F

  cout << endl << "vraag 1b" << endl << endl;
  cout << endl << "zet de volgende temperatuur van graden Celsius om in graden Fahrenheit." << endl;
  cout << "Geef antwoord in hele getallen." << endl;
  cout << endl << randomgetal << endl;
  cin >> inputv2;

  if (antwoordv2 < 0) { //afronding
    antwoordv2 = antwoordv2 - 0.5;
  } else {
    antwoordv2 = antwoordv2 + 0.5;
  }

  antwv2int = antwoordv2; //verander double naar integer

  if (inputv2 == antwv2int || inputv2 == antwv2int - 1 || inputv2 == antwv2int + 1) {
    cout << endl << "correct, het antwoord was " << antwv2int << "." << endl;
    antwcorrect++;
  } else {
    cout << endl << "incorrect, het juiste antwoord was " << antwv2int << "." << endl;
  }

  //-----------aantal correcte antwoorden-----------
  if (net == true) {
	  cout << endl << "u had van het aantal vragen " << antwcorrect << " goed." << endl;
  } else {
	  cout << endl << "je had van het aantal vragen " << antwcorrect << " goed." << endl;
  }

  //-----------bepaling studie-----------
  if (antwcorrect >= 1) {
	if (net == true) {
	  cout << endl << "gefeliciteerd! U bent geschikt voor een exacte studie!" << endl;
	} else {
		cout << endl << "gefeliciteerd! jij bent geschikt voor een exacte studie!" << endl;
	}
    return 0;
  } else {
	  if (net == true) {
		cout << endl << "Helaas is een exacte studie niet geschikt voor u," << endl;
		cout << "Beantwoord de volgende vraag om te zien of u geschikt bent voor een alpha-studie:" << endl;
		cout << endl << "Wie heeft in de middeleeuwen een kaart in vogelvluchtperspectief getekend?" << endl;
		cout << "A)Donatello		B)Da Vinci" << endl;
		cout << "C)Michelangelo		D)Raphael" << endl;
		cin >> mChoiceIn;
	  } else {
		  cout << endl << "Helaas is een exacte studie niet geschikt voor jou," << endl;
		  cout << "Beantwoord de volgende vraag om te zien of je geschikt bent voor een alpha-studie:" << endl;
		  cout << endl << "Wie heeft de Nachtwacht geschilderd?" << endl;
		  cout << "A)Van Gogh		B)Rembrandt" << endl;
		  cout << "C)Vermeer		D)Mondriaan" << endl;
		  cin >> mChoiceIn;
	  }

    if (mChoiceIn == mChoiceAnsS || mChoiceIn == mChoiceAnsL) { //input dezelfde als b of B
      cout << endl << "Het juiste antwoord was: B" << endl;
	  if (net == true) {
		cout << endl << "U bent geschikt voor een alpha-studie!" << endl;
	  } else {
		  cout << endl << "Je bent geschikt voor een alpha-studie!" << endl;
	  }
      cout << "Het programma is voltooid." << endl;
      return 0;
    } else {
      cout << endl << "het juiste antwoord was: B" << endl;
	  if (net == true) {
		cout << endl << "U bent niet geschikt voor een studie." << endl;
	  } else {
          cout << endl << "je bent niet geschikt voor een studie." << endl;
	  }
      cout << "Het programma is voltooid." << endl;
      return 0;
    }
  }
}
