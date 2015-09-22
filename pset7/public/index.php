<?php

    // configuration
    require("../includes/config.php"); 
    $cash = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
    $rows = query("SELECT symbol,shares FROM data WHERE id = ?",$_SESSION["id"]);
    $positions = [];

         foreach ($rows as $row)
         {
              $stock = lookup($row["symbol"]);
              if ($stock !== false)
              {
                   $positions[] = [
                      "name" => $stock["name"],
                      "price" => $stock["price"],
                      "shares" => $row["shares"],
                      "symbol" => $row["symbol"],
                      "Total" => $row["shares"] * $stock["price"]
                       ];
              }
        }
            // render portfolio
            $balance = $cash[0]["cash"];
            render("portfolio.php", ["positions" => $positions, "title" => "Portfolio","balance" => $balance]);


?>
