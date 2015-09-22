<?php

    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("buy.php",["title" => "Buy"]);
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(preg_match("/^\d+$/", $_POST["shares"]))
        {
            $cash = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
            $symbol = $_POST["symbol"];
            $shares = $_POST["shares"];
            $data = lookup($symbol);
            if(isset($data))
            {
                if($cash[0]["cash"] > ($data["price"] * $shares))
                {
                    $insertion = query("INSERT INTO data (id, symbol, shares) 
                        VALUES(?, ?, ?) 
                            ON DUPLICATE KEY 
                                UPDATE shares = shares + ?",
                                $_SESSION["id"], $symbol, $shares, $shares);
                    $balance = $cash[0]["cash"] - ($data["price"] * $shares);
                    $Date = date("Y-m-d H:i:s",time());
                    query("UPDATE users SET cash =  ? WHERE id = ?", $balance, $_SESSION["id"]);
                    query("INSERT INTO Histroy (id,transaction, date, symbol, shares)
                     VALUES(?,?,?,?,?)",$_SESSION["id"], "Buy", $Date, $symbol,$shares );
                     redirect("index.php");
                }
                else
                {
                    apologize("you are out of balance");
                }
            }
            
        }
        else
        {
            apologize("invalied symbol");
        }
     }
    
    
?>
