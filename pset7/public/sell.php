<?php
    // configuration
        require("../includes/config.php");
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
     
        $stockes = [];
        $rows = query("SELECT symbol,shares FROM data WHERE id = ?",$_SESSION["id"]);
        
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $stockes[] = [
                    "name" => $stock["name"],
                    "price" => $stock["price"],
                    "shares" => $row["shares"],
                    "symbol" => $row["symbol"],
                ];
            }
        }
        render("sell.php", ["stockes" => $stockes, "title" => "Sell"]);
     }
     else if($_SERVER["REQUEST_METHOD"] == "POST")
     {
                
                $rows = query("SELECT symbol,shares FROM data WHERE id = ?",$_SESSION["id"]);
                $cash = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
                $symbol = $_POST["symbol"];
                $balance = $cash["0"]["cash"];
                query("DELETE FROM data WHERE id = ? AND symbol = ?",
                            $_SESSION["id"], $symbol);
                            
                $stock = lookup($symbol);
                $balance += ($stock["price"] * $rows[0]["shares"]);
                $Date = date("Y-m-d H:i:s",time());
                query("UPDATE users SET cash =  ? WHERE id = ?", $balance, $_SESSION["id"]);
                query("INSERT INTO Histroy (id,transaction, date, symbol, shares)
                      VALUES(?,?,?,?,?)",$_SESSION["id"], "Sell", $Date, $symbol, $rows[0]["shares"]);
                           
                          
                redirect("index.php");
                
     }

?>
