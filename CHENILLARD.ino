// La Chenille

/*

A faire :

- Séparer les fonctions dans un fichier

*/

int ledArray[] = {2,3,4,5,6,7,8,9,10,11};
int nbLeds = 10;

int const potPin = A0;
int potVal;
int potMap;


void setup()
{
	Serial.begin(9600);

	for(int i = 0; i < nbLeds; i++)
	{
    pinMode(ledArray[i], OUTPUT);
	}
}

void K2000()
{
for(int i = 0; i < nbLeds; i++)
	{
		digitalWrite(ledArray[i], HIGH);
	    delay(potMap);
	    digitalWrite(ledArray[i], LOW);
	    delay(potMap);
	}
	
	for(int j = nbLeds-2; j > 0; j--)
	{
	    digitalWrite(ledArray[j], HIGH);
	    delay(potMap);
	    digitalWrite(ledArray[j], LOW);
	    delay(potMap);
	}
}

void chenillard()
{
for(int i = 0; i < nbLeds; i++)
	{
		digitalWrite(ledArray[i], HIGH);
		delay(potMap);
	}
	
	for(int j = nbLeds-1; j >= 0; j--)
	{
	    digitalWrite(ledArray[j], LOW);
	    delay(potMap);
	}
}

void boucle()
{
for(int i = 0; i < nbLeds; i++)
{
	digitalWrite(ledArray[i], HIGH);
	delay(potMap);
	digitalWrite(ledArray[i], LOW);
	delay(potMap);
}
}

void clignotant()
{
	for(int j = 0; j < nbLeds; j++)
	{
	digitalWrite(ledArray[j], HIGH);
	}
	delay(potMap);
	
	for(int k = 0; k < nbLeds; k++)
	{
	digitalWrite(ledArray[k], LOW);
	}
	delay(potMap);
}

void aleatoire()
{
	int i = random(0, nbLeds);

	Serial.println(i);

	digitalWrite(ledArray[i], HIGH);
	delay(potMap);
	digitalWrite(ledArray[i], LOW);
	delay(potMap);
}

void allon()
{

for(int i = 0; i < nbLeds; i++)
	{
	digitalWrite(ledArray[i], HIGH);
	}
}

void loop()
{
	
	potVal = analogRead(potPin);
	Serial.print("potVal : ");
	Serial.println(potVal);

	potMap = map(potVal, 0, 1023, 10, 100);
	Serial.print("potMap : ");
	Serial.println(potMap);

	int i = random(0);
	Serial.println(i);

	switch (i)
	{
	    case 0 : K2000();			break;
	    case 1 : chenillard();		break;
	    case 2 : boucle();			break;
	    case 3 : clignotant();		break;
	    case 4 : aleatoire();		break;
	   	case 5 : allon();			break;
	   	case 6 : aleatoire();		break;
    }

}