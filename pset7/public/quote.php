    <?php
    
    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    elseif($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $row = lookup($_POST["symbol"]);
        if($row === false)
        {
            apologize("Symbol not found");
        }
        else
        {
             $message = $row['name'];
             $message .= " ({$row['symbol']}) ";
             $message .= " $ {$row['price']}";
             render("quote.php", ["message" => $message]);

        }
   }
?>
