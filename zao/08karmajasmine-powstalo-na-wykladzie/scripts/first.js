function cenzor(txt, badWords) {
    if (txt.id) {
        txt.words.forEach(function(element) {
            var re = new RegExp(element, "g");
            var e = document.getElementById(txt.id);
            e.innerText = e.innerText.replace(re, "...");
        });
    } else {
        badWords.forEach(function(element) {
            var re = new RegExp(element, "g");
            txt = txt.replace(re, "...");
        });
        return txt;
    }
}