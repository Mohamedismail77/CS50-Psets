
<form action="sell.php" method="post">
    <fieldset>
        
           <div class="form-group">
           <select class="form-control" name="symbol">
                <option value=""> </option>
                 <?php foreach ($stockes as $stock): ?> 
                    <option name = "symbol" value="<?php echo $stock['symbol'] ?>"><?= $stock["symbol"]?> </option>
                 <?php endforeach ?>         
           </select>
           </div>
        <div class="form-group">
            <button type="sell" class="btn btn-default">sell</button>
        </div>
        
    </fieldset>
</form>
