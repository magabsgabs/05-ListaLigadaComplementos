#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL || novo->valor < primeiro->valor)
	{
		novo->prox = primeiro;
		primeiro = novo;
	}
	else
	{
		NO* aux = primeiro;
		while (aux->prox != NULL && aux->prox->valor < novo->valor)
		{
			if (aux->prox->valor == novo->valor)
			{
				free(novo);
				return; // N�o permite valores duplicados
			}
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

void excluirElemento()
{
	int valor;
	cout << "Digite o valor a ser excluido: ";
	cin >> valor;

	if (primeiro == NULL) {
		cout << "Lista vazia." << endl;
		return;
	}

	NO* aux = primeiro;
	NO* anterior = NULL;

	// Casos especiais
	if (primeiro->valor == valor) {
		primeiro = primeiro->prox;
		free(aux);
		cout << "Elemento " << valor << " excluido." << endl;
		return;
	}

	while (aux != NULL && aux->valor != valor) {
		anterior = aux;
		aux = aux->prox;
	}

	if (aux == NULL) {
		cout << "Elemento n�o encontrado." << endl;
		return;
	}

	anterior->prox = aux->prox;
	free(aux);
	cout << "Elemento " << valor << " excluido." << endl;
}

void buscarElemento()
{
	int valor;
	cout << "Digite o valor a ser buscado: ";
	cin >> valor;

	NO* aux = primeiro;

	while (aux != NULL && aux->valor < valor) {
		aux = aux->prox;
	}

	if (aux == NULL || aux->valor != valor) {
		cout << "Elemento n�o encontrado." << endl;
	}
	else {
		cout << "Elemento " << valor << " encontrado." << endl;
	}
}
 