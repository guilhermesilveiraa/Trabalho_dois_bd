#include <iostream>
#include <cstring>

using namespace std;
//só um teste 
class Autor{
	private:
		char nome[50];
	public:
		void setNome(const char* Nome) { strcpy(this->nome,nome); }

};
class Artigo{
	private:
		int ID;
		char titulo[300];
		int ano;
		Autor autores[150];
		int citacoes;
		char Snippet[1024];
	public:
		int getID(){return ID;}
		char* getTitulo(){return titulo;}
		
		void setID(int ID) { this->ID = ID; }
		void setTitulo(const char* titulo) { strcpy(this->titulo,titulo); }
		void setAno(int ano) { this->ano = ano; }
		void setAutores(Autor* autores) { 
		memcpy(this->autores, autores, sizeof(Autor) * 150); 
		}
		void setCitacoes(int citacoes) { this->citacoes = citacoes; }
		void setSnippet(const char* Snippet) { strcpy(this->Snippet,Snippet); }
};


int main(){
		cout << "olá mundo!\n";
		Artigo a1;
		a1.setTitulo("Building Theories in Software Enginner\n");
		Autor autor1;
		
		a1.setAutores({});
		cout << "título: "<< a1.getTitulo() << "autor: "; 
}
