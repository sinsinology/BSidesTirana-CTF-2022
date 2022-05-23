# BSides Tirana 2022 Web Challenges & Solutions




### Insider

This is a web app to detect burp suite (for real?!)
Upon Visiting the page, the user will be presented with a alert saying "Don't Cheat" (If browser is proxied through burp)

the jquery has been modified and a snippet of code has been added to detect `http://burp/favicon.ico`, since by default, burp suite will be listening at that address, if the image load is successful that means the browser is being proxied through burp and user recived the mssage saying `Don't Cheat` and a `logo.png` gets loaded and if there is no burp, then a `logo.jpg` gets loaded


![BSides-Tirana](01.png)


![BSides-Tirana](02.png)

![BSides-Tirana](02-B.png)


![BSides-Tirana](03.png)


Requesting logo.jpg will result in `Good: BASE64-Flag`


 



### Comedian

The web app allows you to serch for jokes



![BSides-Tirana](04.png)
Clicking on the image takes us to another url that says you are not the joke master
![BSides-Tirana](04-B.png)

Because it is checking for the src-addr to be from local host
![BSides-Tirana](07.png)


the jokes are retirved from a 3rd-party website

![BSides-Tirana](05.png)

The path is not controllable, only the host is controllable

![BSides-Tirana](06.png)

It's possible to send the Comedian to attacker controlled website, hosting a index.php to send a 302 redirect (gaining control over full url) sending comedian to jokemaster (127.0.0.1) to retrieve the flag



![BSides-Tirana](08.png)



```
<?php

header('Location: http://localhost/jokemaster')

?>
```


