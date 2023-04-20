<!DOCTYPE html>
<html>
    <head>
        <title>Zachary Craig | Multiplication Table</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <body>
    <?php 
        $size = $_POST["size"];
        echo "<table border='1'>";
        for ($row = 0; $row <= $size; $row++) {
            echo "<tr>";
            for ($col = 0; $col <= $size; $col++) {
                if ($row == 0 && $col == 0) 
                {
                    echo "<td></td>";
                }
                else if ($row == 0) 
                {
                    echo "<td>$col</td>";
                } 
                else if ($col == 0) 
                {
                    echo "<td>$row</td>";
                } 
                else 
                {
                    if($row == $col)
                    {
                        echo "<td class='dark-gray'>" . $row * $col . "</td>";
                    }
                    else
                    {
                        echo "<td>" . $row * $col . "</td>";
                    }
                }
            }
            echo "</tr>";
        }
        echo "</table>";      
    ?>
    </body>
</html>

