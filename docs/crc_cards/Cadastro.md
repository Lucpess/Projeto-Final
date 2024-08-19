# CRC Card: Classe `Cadastro`

## Responsabilidades
- Gerenciar o cadastro de jogadores. 
- Fornecer métodos para adicionar, remover, verificar a existência e listar jogador por nome ou apelido.
- Manter os dados de jogadores em um arquivo e garantir confluência entre o sistema e o arquivo.
- Registrar os resultados das partidas e atualizar as estatísticas dos jogadores no mapa e no arquivo txt.

## Colaboradores
- Jogador: Interage com a classe Jogador para manipular dados como nome, apelido, vitórias e derrotas.
- Arquivo cadastro_jogadores: Utiliza operações para salvar e carregar o cadastro dos jogadores no arquivo.
