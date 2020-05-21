#include <iostream>
#include <map>
using namespace std;

int main()
{
    //Creo un mapa para guardar el valor de cada letra.
    map<char, int> mRomanValues = { {'I', 1}, {'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000} };

    bool isRunning = true;
    string sRoman;

    while (isRunning)
    {
        //Pido al usuario que ingrese el número en romano.
        cout << "Write a number in roman numerals, type 'Q' to exit" << endl;
        cin >> sRoman;

        if (sRoman[0] != 'Q')
        {
            int iArab = 0;
            bool isValid = true;

            //Recorro cada elemento del string
            for (size_t i = 0; i < sRoman.length(); i++)
            {
                //Compruebo que las letra actual sea valida.
                if (mRomanValues.count(sRoman[i]))
                {
                    //Si el siguiente valor es menor al actual le sumo a mi total el valor actual
                    if (mRomanValues[sRoman[i + 1]] <= mRomanValues[sRoman[i]])
                    {
                        iArab += mRomanValues[sRoman[i]];
                    }
                    else //Si es mayor el siguiente valor le resto el valor actual a mi total.
                    {
                        iArab -= mRomanValues[sRoman[i]];
                    }
                }
                else
                {
                    isValid = false;
                }
            }

            if (isValid)
            {
                cout << iArab << endl;
            }
            else
            {
                cout << "Invalid number" << endl;
            }
            cout << endl;
        }
        else
        {
            isRunning = false;
        }
        
    }

    cin.get();
}
