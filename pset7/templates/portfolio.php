<ul class="nav nav-pills" style="padding-left:25%; padding-bottom:5px;">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="changepw.php"><strong>Change password</strong></a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>
<table class="table table-striped">

    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>

    <tbody>

    <?php foreach ($positions as $position): ?>
        <tr style="text-align:left;">
            <td><?= strtoupper($position["symbol"]) ?></td>
            <td><?= $position["name"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td><?= "$".$position["price"] ?></td>
            <td><?= "$".$position["Total"] ?></td>
        </tr>
    <?php endforeach ?>
    <tr style="text-align:left;">
        <td colspan="4">CASH</td>
        <td><?= "$".number_format($balance,2)?></td>
    </tr>
    </tbody>

</table>

