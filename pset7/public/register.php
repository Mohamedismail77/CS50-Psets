<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        if(!isset($_POST["username"]) || !isset($_POST["password"]))
        {
            apologize("please enter user name and password");
            
        }elseif($_POST["password"] !== $_POST["confirmation"]){
        
            apologize("password didn\'t match");
            
        }else{
            
            $insertion  = query("INSERT INTO users (username, hash, cash) 
                        VALUES(?, ?, 10000.00)", $_POST["username"], 
                        crypt($_POST["password"]));
             if($insertion === false)
             {
               apologize("invalied user name");
             }else{ 
                redirect("index.php");
             }
                    
        }
    }

?>
