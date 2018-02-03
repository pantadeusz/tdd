// Stosujemy domknięcie (closure)
(function( $ ) {
    var elemId = "noid"; 
    // definicja wtyczki
    $.fn.appendInput = function( options ) {
        if (options.getId) {
            elemId = options.getId();
        } else {
            elemId = options;
        }
        this.append("<input type='text' id='" + elemId + "' />");
    };
})( jQuery );
