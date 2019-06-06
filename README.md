# Implementação Pontos em Polígonos
Implementação em C++ do código para verificação de pontos em polígono para o trabalho proposto pelo Dr Gilberto Queiroz pra disciplina de Computação Aplicada no Instituto Nacional de Pesquisas Espaciais do Programa de Pós Graduação em Computação Aplicada.
Desenvolvido pelos alunos de mestrado Adriano Almeida e Helvécio Neto.
Artigo inicial: Eric Haines. 1994. Point in polygon strategies. In Graphics gems IV, Paul S. Heckbert (Ed.). Academic Press Professional, Inc., San Diego, CA, USA 24-46.

## Objetivo do programa
Verificação de pontos em polígonos utilizando dados de alertas de desmatamento na Amazônia Legal em 2017. Para este exemplo os polígonos são os municípios do estado do Pará. Já os pontos são os centroides das áreas com aleta de desmatamento.  Os dados utilizados para este trabalho foram obtidos em [http://www.obt.inpe.br/deter/dados/2017/](http://www.obt.inpe.br/deter/dados/2017/).

## Estrutura
- **main.cpp**: Arquivo com a função principal.
- **Utils.hpp**: Arquivo com algumas funções auxiliares para fazer o tratamento das linhas lidas a partir dos arquivos.
- - **Geometry.hpp**: Arquivo de cabeçalho com a definição das classes e métodos principais do programa.
- **Geometry.cpp**: Implementação dos métodos do programa.
- **points**: Pasta com os centroides das áreas com alertas de desmatamento na Amazônia Legal. Nessa pasta deverão ficar os pontos utilizados no teste.
- **polygons**: Pasta com os pontos com as coordenadas das fronteiras de todos os 144 municípios do Pará. Nessa pasta deverá ficar as cidade que deverão ser utilizadas durante o teste.
- **polygons_city**: Nessa pasta estão todos os arquivos com as coordenadas dos municípios.
- **points_deforestation**:  Nessa pasta estão os pontos de desmatamento de janeiro a novembro de 2017.

> **Nota**:  A configuração atual do programa irá verificar os focos de desmatamento no mês de janeiro e fevereiro de 2017 para todos os municípios do estado do Pará. Caso queira mudar essa configuração, deverá ser adicionado ou removidos os arquivos nas pastas **points** e/ou **polygons**.

## Execução

```console
git clone https://github.com/AdrianoPereira/PointInPolygon.git
``` 

```console
cd PointInPolygon
``` 

```console
cmake . && make
``` 

```console
./point_in_polygon
``` 
