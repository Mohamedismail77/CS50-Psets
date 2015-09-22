<?php


    //config
    require("../includes/config.php");
    $rows = query("SELECT * FROM Histroy WHERE id = ?",$_SESSION["id"]);
    $positions = [];

         foreach ($rows as $row)
         {

                   $positions[] = [
                      "transaction" => $row["transaction"],
                      "date" => $row["date"],
                      "shares" => $row["shares"],
                      "symbol" => $row["symbol"],
                       ];

        }
    render("history.php",["title" => "History", "positions" => $positions])


?>
