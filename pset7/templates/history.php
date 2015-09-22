<table class="table table-striped">

    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/time</th>
            <th>Symbol</th>
            <th>Shares</th>
        </tr>
    </thead>

    <tbody>

    <?php foreach ($positions as $position): ?>
        <tr style="text-align:left;">
            <td><?= $position["transaction"] ?></td>
            <td><?= $position["date"] ?></td>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["shares"] ?></td>
        </tr>
    <?php endforeach ?>
    </tbody>

</table>
