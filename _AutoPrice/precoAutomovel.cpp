#include<iostream>
#include<locale>
#include<string>
using namespace std;

int main(){
	setlocale(LC_ALL,"ptb");
	int i, escolha, validadorOp[5], nenhum = 0, trioEletrico = 1, arCondicionado = 2, direcaoH = 3, opCompleto = 4;
	float valVeicFab, valFinal, valVeicIpi, somaDeOpcionais, descontoCompleto, ipiOpcionais[5];
	bool validador = false, c, exit;
	char simOuNao;
		
	cout << "************************************************************************************************************************";
	cout << "*************************************** Opcionais e pre�o do Ve�culo ***************************************************";
	cout << "************************************************************************************************************************";
	cout << "\nSeja bem vindo! Neste sistema voc� poder� escolher qual os opcionais se enquadram melhor ao seu estilo.";
	cout << "\nComece inserindo o valor de f�brica do seu autom�vel (Incluindo os centavos): R$";
	cin >> valVeicFab;
		valVeicIpi = valVeicFab/100*8;
		valVeicIpi = valVeicIpi + valVeicFab;
	cout << "\nMuito bem, vamos ao menu de opcionais: \n";
	cout << "0)Nenhum\n" << "1)Trio El�trico\n" << "2)Ar Condicionado\n" << "3)Dire��o Hidr�ulica\n" << "4)Completo\n";
		ipiOpcionais[1] = valVeicIpi/100*2;
		ipiOpcionais[2] = valVeicFab/100*2;
		ipiOpcionais[3] = valVeicFab/100*2;
		ipiOpcionais[4] = ipiOpcionais[1]+ipiOpcionais[2]+ipiOpcionais[3];
			do{
				cout << "\nDigite o n�mero de um opcional: ";
				exit = false;
					do{
						cin >> escolha;
							if(validadorOp[escolha] == escolha){
								cout << "Opcional j� selecionado, escolha outro: ";
								c = false;
							}else{
								c = true;
							}
					}while(c == false);
					switch(escolha){
						case 0: cout << "\nNenhum opcional escolhido.";
						break;
						case 1: cout.precision(4); cout << "Voc� escolheu: Trio El�trio.\nValor: R$" << ipiOpcionais[1];
						break;
						case 2: cout.precision(4); cout << "Voc� escolheu: Ar Condicionado.\nValor: R$" << ipiOpcionais[2];
						break;
						case 3: cout.precision(4); cout << "Voc� escolheu: Dire��o Hidr�ulica.\nValor: R$" << ipiOpcionais[3];
						break;
						case 4: cout.precision(4); cout << "Voc� escolheu: Todos Opcionais.\nValor: R$" << ipiOpcionais[4]; validador = true, exit = true;
						break;
						default: cout << "Escolha um n�mero v�lido!";
					}
					for(i=1;i<=4;i++){
						if(escolha == i){
							validadorOp[i] = i;
						}
					}
					while(exit == false){
						cout << "\nEscolher mais um(s|S ou n|N)? ";
						cin >> simOuNao;
							if(simOuNao == 's' || simOuNao == 'S'){
								validador = false;
								exit = true;
							} else if(simOuNao == 'n' || simOuNao == 'N'){
										validador = true;
										exit = true;
									} else {
										cout << "Digite uma resposta v�lida!!";
										exit = false;
									}
					}
					for(i=1;i<=4;i++){
						if(i==escolha && i!=4){
							somaDeOpcionais += ipiOpcionais[i];
						}else if(i==escolha && i==4){
									somaDeOpcionais = ipiOpcionais[i];
								}
					}						
			}while(validador == false);
		
		valFinal = valVeicIpi + somaDeOpcionais;
		
		if(escolha == 4){
			valFinal -= valFinal/100*3.5;
		}	
		
	cout << "\nValor dos opcionais: R$" << somaDeOpcionais;
	cout << fixed << cout.precision(2);
	cout << "\nValor final do autom�vel: R$" << valFinal;
	system("pause");	
}
