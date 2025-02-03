# BitDogLab Interruptions

Repositório para a tarefa sobre interrupções do Raspberry Pi Pico W, do curso de capacitação Embarcatech.

## Descrição do Projeto

Este projeto demonstra o uso de interrupções no Raspberry Pi Pico W para controlar uma matriz de LEDs e um LED RGB utilizando os botões A e B da placa BitDogLab.

## Funcionalidades

- Piscar o LED vermelho do LED RGB continuamente 5 vezes por segundo.
- Incrementar o número exibido na matriz de LEDs ao pressionar o botão A.
- Decrementar o número exibido na matriz de LEDs ao pressionar o botão B.
- Exibir números de 0 a 9 na matriz de LEDs utilizando LEDs WS2812.

## Demonstração

[Assista ao vídeo da demonstração](https://www.dropbox.com/scl/fi/ymj6y6t767gvat7lg08u7/Tarefa_Interrup-es.mp4?rlkey=ifr3i33jaqszk3syztf37560a&st=vl7pqhkq&dl=0)

## Pré-requisitos

1. **Instalar o SDK do Raspberry Pi Pico**:
   - Siga as instruções no [site oficial](https://github.com/raspberrypi/pico-sdk) para instalar o SDK do Raspberry Pi Pico.

2. **Instalar o CMake**:
   - Baixe e instale o CMake a partir do [site oficial](https://cmake.org/download/).

3. **Instalar o Ninja**:
   - Baixe e instale o Ninja a partir do [site oficial](https://ninja-build.org/).

## Instalação

1. **Clone o repositório**:
   ```sh
   git clone https://github.com/seu-usuario/bitdoglab-interruptions.git
   cd bitdoglab-interruptions
   ```
2. Configurar o ambiente no Visual Studio Code:
    - Abra o Visual Studio Code no diretório do projeto.
    - Certifique-se de que as configurações no arquivo settings.json estão corretas e apontam para os caminhos corretos do SDK, CMake, Ninja, etc.

## Como utilizar

1. **Compilar o projeto**:
    - No Visual Studio Code, abra a extensão Raspberry Pi Pico Project, procure e selecione a função Compile Project.

2. **Execute o projeto**:
    - Retorne aos arquivos do projeto, abra o arquivo ``diagram.json``, clique no botão verde ``Start the simulation``.

3. **Utilize os botões A e B no simulador Wokwi para interagir com a matriz de LEDs conforme programado.**

## Estrutura do Projeto

- ``.vscode``: Diretório contendo configurações do Visual Studio Code.
- ``build``: Diretório onde os arquivos compilados serão gerados.
- ``CMakeLists.txt``: Arquivo de configuração do CMake para o projeto.
- ``bitdoglab-interruptions.c``: Código fonte principal do projeto.
- ``matriz_leds.c`` e ``matriz_leds.h``: Código fonte e cabeçalho para controle da matriz de LEDs.
- ``diagram.json``: Diagrama de conexões dos componentes.
- ``pico_sdk_import.cmake``: Arquivo de importação do SDK do Raspberry Pi Pico.
- ``wokwi.toml``: Arquivo de configuração para simulação no Wokwi.
- ``pio_matrix.pio``: Código PIO para controle da matriz de LEDs.

## Contribuição

1. Faça um fork do projeto.
2. Crie uma branch para sua feature (git checkout -b feature/nova-feature).
3. Commit suas mudanças (git commit -m 'Adiciona nova feature').
4. Faça o push para a branch (git push origin feature/nova-feature).
5. Abra um Pull Request.