• DESCRIÇÃO: Neste projeto o objetivo é criar um jogo em 3D usando uma técnica chamada ray casting, esta técnica consiste em disparar vários raios a partir da posição do player até que os mesmos “colidam” com algo. A partir deste ponto, calculamos a distância entre o ponto de origem e o ponto final usando técnicas de trigonometria, com esse valor conseguimos determinar qual será o tamanho de cada objeto no cenário na representação 3D. Eu gostei deste projeto pois ele me permitiu entender mais o que de fato é um 3D e entender o básico de como funciona um motor gráfico.

• IMPORTÂNCIA DO PROJETO: Este projeto permite que as pessoas possam criar os seus jogos com o mapa que elas quiserem, tendo a possibilidade de personalizarem as cores do céu, do chão e as texturas das paredes e inserir sprits (objetos) no cenário.

COMO Utilizar: Basta usar o comando "make" na raiz do repositorio, sera criado um arquivo com o nome "cub3D". Com isso, basta executar este arquivo passando como segundo parametro o mapa que você quer renderizar. Além disso, é possivel salvar a imagem inicial do jogo usando a flag "--save", ao executar este comando sera gerado um arquivo "photo.bmp" com a imagem.
Exemplo: ./cub3D /mymaps/map14.cub

Exemplo: ./cub3D /mymaps/map14.cub --save
