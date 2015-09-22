<?php

    require("../includes/config.php");
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("changepw.php",["title" => "Change Password"]);
    }
    elseif($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        $rows = query("SELECT * FROM users WHERE id = ?",$_SESSION["id"]);
        $old_pass = crypt($_POST["oldpassword"], $rows[0]["hash"]);
        if($old_pass == $rows[0]["hash"])
        {
            if($_POST["newpassword"] === $_POST["confirmation"])
            {
                 query("UPDATE users SET hash =  ? WHERE id = ?",
                 crypt($_POST["newpassword"]), $_SESSION["id"]);
                 redirect("login.php");
            }
            else
            {
                apologize("password confirmation didn't match");
            }

        }
        else
        {
            apologize("invalied password");
        }
    }

    

?>
