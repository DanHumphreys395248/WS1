#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{

    class WordCount
    {
    public:
        string word;
        int count;
    };

    cout << "Hello World!\n";
    //initialises the storage vectors for the words and their tallies
    vector <WordCount> listOfWords;
    //opens the file
    fstream reader_;
    reader_.open("input.txt");
    if (reader_.is_open())
    {
        string ES;
        while(getline(reader_,ES, '.'))
        {
            string IndivWord;
            stringstream TEMP1(ES);
            while (getline(TEMP1, IndivWord, ' '))
            {
                string ToCheck;
                stringstream TEMP2(IndivWord);
                while (getline(TEMP2, ToCheck, '\n'))
                {
                    if (listOfWords.size() == 0)
                    {
                        WordCount EmptyAdd;
                        EmptyAdd.word = ToCheck;
                        EmptyAdd.count = 1;
                        listOfWords.push_back(EmptyAdd);
                    }
                    else
                    {
                        try
                        {
                            bool added = false;
                            bool OOR = false;
                            int A = 0;
                            while (not added)
                            {
                                while (not OOR)
                                {
                                    WordCount Element = listOfWords[A];
                                    if (Element.word == ToCheck)
                                    {
                                        listOfWords[A - 1].count + 1;
                                        added = true;
                                        break;
                                    }
                                    A++;
                                    if (A > listOfWords.size() - 1)
                                    {
                                        OOR = true;
                                    }
                                }
                                WordCount adder;
                                adder.word = ToCheck;
                                adder.count = 1;
                                listOfWords.push_back(adder);
                                added = true;
                                break;
                                

                            }
                        }
                        catch (out_of_range)
                        {
                            WordCount OORadd;
                            OORadd.word = ToCheck;
                            OORadd.count = 1;
                            listOfWords.push_back(OORadd);
                        }
                    }
                }
            }
        }
        if (listOfWords.size()<1)
        {
            cout << "file empty or program error";
        }
        else
        {
            bool finished = false;
            int CID = 0;
            while (not finished)
            {
                if (CID > (listOfWords.size() - 1))
                {
                    finished = true;
                }
                else
                {
                    cout << listOfWords[CID].word;
                    cout << " appeared ";
                    cout << listOfWords[CID].count;
                    cout << " time(s).\n\n";
                    CID ++;
                }
            }
        }
    }
    // tells the user if there's no open file.
    else {
        cout << "unable to read\n";
    }
    return 0;
}

