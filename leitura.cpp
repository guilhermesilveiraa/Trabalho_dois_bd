#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;
//só um teste 

class RegArtigo{ //registro de artigo
	private:
		int ID;
		char titulo[300];
		int ano;
		//std::vector<std::string> autores(150);
		int citacoes;
		char Snippet[1024];
	public:
		int getID(){return ID;}
		char* getTitulo(){return titulo;}
		char* getSnippet(){return Snippet;}
		
		void setID(int ID) { this->ID = ID; }
		void setTitulo(const char* titulo) { strcpy(this->titulo,titulo); }
		void setAno(int ano) { this->ano = ano; }
		//void setAutores(string autores) {}
		void setCitacoes(int citacoes) { this->citacoes = citacoes; }
		void setSnippet(const char* Snippet) { strcpy(this->Snippet,Snippet); }
};

class PosicaoHash{ //lista encadeada de uma posição na tabela hash (bloco)
	RegArtigo *artigo;
	PosicaoHash	*proximo;	
};

PosicaoHash ** tabela_hash_t;

int tamanho_tabela_hash;

void imprime1(){
    ifstream arquivo("artigo.csv");//abrindo arquivo
    if (arquivo.is_open()){
        char buffer[100];
        arquivo.read(buffer, 100);
        cout << "Endereço 1: " << (void*)&buffer[0] << " dado: " << buffer << "\n";
    }
    arquivo.close();
}

void imprime2(){
    FILE* arquivo = fopen("artigo.csv","r");//abrindo arquivo
    if (arquivo){
        printf("Endereço 2: %p\n",arquivo);
    }    
    fclose(arquivo);
}

void le_arquivo(){
    std::ifstream arquivo("artigo.csv");
    RegArtigo artigo;
    int endereco;
    char* buffer_linha;
    std::chrono::seconds delay_segundos(1); //delay de teste
    while (!arquivo.eof()){
        buffer_linha = new char[10000];
        arquivo.getline(buffer_linha, 10000);
        std::cout << buffer_linha << "\n*******************************************\n";
        delete[] buffer_linha;
        std:: this_thread::sleep_for(delay_segundos);
    }
    arquivo.close();
   
}
int main(){
    imprime1();
    imprime2();
    le_arquivo();
    RegArtigo a1;
}