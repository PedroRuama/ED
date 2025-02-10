<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Fisica</title>
    <link rel="stylesheet" href="./style/index.css">
</head>



<?php
if (isset($_POST['num_carros'])) {
    $n_carros = $_POST['num_carros'];
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
        <!-- <div class="box">
            <div class="nomes">
                <a href="./gerarCarros.php">
                    <h3>Professora: </h3>
                </a>
                Adriana de Oliveira Delgado Silva
            </div>
        </div> -->
    </div>

    <div class="titulo">
        <h1>Corrida Fisica!!!</h1>
    </div>
    <br>

    <form action="index.php" method="post" class="forms_">
        <div class="inputGroup">
            <input class="input" size="20" required minlength="1" maxlength="11" type="search" name="num_carros">
            <label for="">Insira o numero de carros</label>
        </div>
        <button type="submit" class="btn">Criar</button>
    </form>
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

    <div class="grade">

        <form action="gerarCarros.php" method="post" class="forms_">
            <input style="display: none; " size="10" minlength="1" type="search" name="n_car" value="<?php echo $n_carros ?>">
            <?php

            for ($i = 0; $i < $n_carros; $i++) {

            ?>
                <div class="card_c">
                    Carro&nbsp;&nbsp;<?= $i ?>
                    <div class="inputGroup">
                        <p class="label_select">Posição Inicial</p>
                        <input class="input" size="10" required minlength="1" type="search" name="P_<?= $i ?>">
                    </div>

                    <div class="inputGroup">
                        <p class="label_select">Velocidade Inicial</p>
                        <input class="input" size="10" required minlength="1" type="search" name="V_<?= $i ?>">
                    </div>
                    <div class="inputGroup">
                        <p class="label_select">Aceleração</p>
                        <input class="input" size="10" required minlength="1" type="search" name="A_<?= $i ?>">
                    </div>


                </div>
            <?php
            }
            ?>
            <button type="submit" class="btn">Enviar</button>
        </form>
    </div>
</body>

</html>