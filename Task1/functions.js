function passwordCheck() 
{
    var password = document.getElementById("password-check").elements["password"].value;
    var passCheck = document.getElementById("password-check").elements["pass-check"].value;

    if (password.length < 8 || passCheck.length < 8)
    {
        alert("Password must be at least 8 characters long");
    } 
    else if (password != passCheck)
    {
        alert("Passwords do not match");
    }
    else
    {
        alert("Passwords match");
    }
}

function practice2() 
{
    var red_border = document.getElementById("red_border").value;
    var green_border = document.getElementById("green_border").value;
    var blue_border = document.getElementById("blue_border").value;
    var red_background = document.getElementById("red_background").value;
    var green_background = document.getElementById("green_background").value;
    var blue_background = document.getElementById("blue_background").value;
    var border_width = document.getElementById("border_width").value;

    var element = document.getElementById("rgb_changing");
    element.style.borderColor = `rgb(${red_border},${green_border},${blue_border})`;
    element.style.borderWidth = border_width + "px";
    element.style.backgroundColor = `rgb(${red_background},${green_background},${blue_background})`;
}