#include <iostream>
#include <cstring>

using namespace std;
const int cols = 16, rows = 15;

 char words[rows][cols] = {"tgbwwinterwsesn",
                                "aaunttmmhfoodnb",
                                "jlwcqldzmpmvdmr",
                                "asagmquwvvbsohi",
                                "bwplotanadtpgnc",
                                "rewngodjcpnatnk",
                                "eeotwosbqharrsa",
                                "azcgeswewnaknpb",
                                "dinnerqodlwdcar",
                                "onopkwmparktzcc",
                                "qbfrogmamwpweey",
                                "lqzqnnmrzjjsclg",
                                "mosgzczetdbooto",
                                "pdcrzmsngrdnrpz",
                                "ohnkzwaterjgtra"};

//char *getWordVertical(int);
//char *reverse(char *);
bool searchVertical(char * word){
    bool ada;
    char firstWord = word[0];
    int wordLen = strlen(word);
    //Sequential search
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (words[i][j] == firstWord) {
                //ke arah bawah
                if(i+wordLen < rows){
                    ada = true;
                    for(int k=0;k<wordLen&&ada;k++){
                        if(words[i+k][j] != word[k]){
                            ada = false;
                        }
                    }
                    if(ada){
                        return true;
                    }
                }
                //Ke arah kiri
                if(j-wordLen >= 0){
                    ada = true;
                    for(int k=0;k<wordLen&&ada;k++){
                        if(words[i-k][j] != word[k]){
                            ada = false;
                        }
                    }
                    if(ada){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool searchHorizontal(char * word){
    bool ada;
    char firstWord = word[0];
    int wordLen = strlen(word);
    //Sequential search
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (words[i][j] == firstWord) {
                //ke arah kanan
                if(j+wordLen < cols){
                    ada = true;
                    for(int k=0;k<wordLen&&ada;k++){
                        if(words[i][j+k] != word[k]){
                            ada = false;
                        }
                    }
                    if(ada){
                        return true;
                    }
                }
                //Ke arah kiri
                if(j-wordLen >= 0){
                    ada = true;
                    for(int k=0;k<wordLen&&ada;k++){
                        if(words[i][j-k] != word[k]){
                            ada = false;
                        }
                    }
                    if(ada){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    char word[16];
    int n;
    cin>>n;
    for (int i=0;i<=n;i++){
        cin.getline(word,16,'\n');
        if(i!=0){
            if (searchVertical(word) || searchHorizontal(word))
                cout << "Ada\n";
            else 
                cout << "Tidak Ada\n";
        }
    }
    return 0;
}
