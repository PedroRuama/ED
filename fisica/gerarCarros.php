<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tabela de Corrida</title>
    <link rel="stylesheet" href="./style/index.css">
</head>



<?php
if (isset($_POST['n_car'])) {
    echo $n_carros = $_POST['n_car'];
} else {
    $n_carros = 0;
}






?>














<body>

    <div class="head">

        <div class="box">
            <div class="nomes">
                <h3>Nomes: </h3>
                <p>Alisson</p>
                <p>Rodrigo</p>
                <p>Pedro Ruama</p>
            </div>

            <div class="RA">
                <h3>RA: </h3>
                <p>831645</p>
                <p>831409</p>
                <p>831660</p>
            </div>


        </div>
        <div class="box">
            <div class="nomes">
                <a href="./gerarCarros.php">
                    <h3>Professora: </h3>
                </a>
                Adriana de Oliveira Delgado Silva
            </div>
        </div>
    </div>

    <div class="titulo">
        <h1>Corrida Fisica!!!</h1>
    </div>
    <div class="dados">
        <div class="box">
            <div>
                <h3>Dados da pista: </h3>
                Numeros de Carros: <b> <?php echo $n_carros; ?></b> <br>
                Distancia Máxima da pista: <b>100m</b> <br>

            </div>
        </div>
        <div class="box">
            <div>
                <h3>Unidades de Medida SI: </h3>
                Distancia: <b>m</b> <br>
                Velocidade <b>m/s</b> <br>
                Aceleração <b>m/s²</b> <br>

            </div>
        </div>
    </div>


    <a href="index.php"><button type="button" class="btn">voltar</button></a>

    <br>
    <br>

    <div class="table-container">
        <h1>Tabela de Resultados da Corrida</h1>
        <table class="race-table">
            <thead>
                <tr>
                    <th>Colocação</th>
                    <th>Tempo</th>
                    <th>Velocidade (km/h)</th>
                    <th>Aceleração (m/s²)</th>
                    <th>Posição</th>
                </tr>
            </thead>
            <tbody>
                <?php

                for ($i = 0; $i < $n_carros; $i++) {
                    $velo =  $_POST["V_" . $i];
                    $ace =  $_POST["A_" . $i];
                    $pos = $_POST["P_" . $i];

                    $varia_Pos = 100 - $pos;

                    if ($ace == 0) {
                        $tempo = $varia_Pos / $velo;
                    } else {
                        $t1 = ($velo * $velo) + ((2 * $ace) * $varia_Pos);
                        if ($t1 < 0) {
                            echo "Erro. o caro " . $i . " vai para tras";
                        } else {

                            $tempo =  (sqrt($t1) - $velo) / $ace;
                        }
                    }


                ?>
                    <tr>
                        <td>1º</td>
                        <td><?php echo $tempo?></td>
                        <td><?php echo $velo ?></td>
                        <td><?php echo $ace ?></td>
                        <td><?php echo $pos ?>m </td>
                    </tr>
                <?php
                }
                ?>

            </tbody>
        </table>
    </div>
</body>

</html>