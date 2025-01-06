//esse programa irá printar no terminal o seu PID atual(para ser utilizado pelo client), e ficará aguardando os sinais enviados pelo client, que serão tratados com uma função para interpretar os sinais e gerar um caracter

//esboço
void	convert_signal(int signal)
{
	char	byte = '\0'; //nessa etapa, é o mesmo que escrever byte = 0b00000000
	int	count = 7;//os 8 bits de um byte -> de 7 a 0

    //se o sinal enviado for 1, coloque 1 no bit equivalente
	if (signal == SIGUSR1)
		byte = byte | (1 << count--);
    //se o sinal enviado for 0, mantenha 0 no bit equivalente
	else if (signal == SIGUSR2)
		count--;
    //se tiver corrido todos os 8 bits(contou de 7 até 0), formamos um caractere em byte, imprimimos ele e resetamos as contagens
	if (count == -1)
	{
		ft_printf("%c", byte);
		count = 7;
		byte = '\0';
	}
}

int main (void)
{
    ft_printf("%i\n", getpit()); //vai imprimir na tela  PID atual
    //chamada da convert_signal
    return (0);
}