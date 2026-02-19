<form method="post">
    Enter a number: <input type="text" name="input"><br><br>
    <input type="submit" name="submit" value="Submit">
</form>

<?php
if ($_POST) {
    $input = (int)$_POST['input'];

    if ($input < 2) {
        echo "The number $input is not prime";
        exit;
    }

    $isPrime = true;

    for ($i = 2; $i <= $input - 1; $i++) {
        if ($input % $i == 0) {
            $isPrime = false;
            break;
        }
    }

    if ($isPrime) {
        echo "The number $input is prime";
    } else {
        echo "The number $input is not prime";
    }
}
?>

