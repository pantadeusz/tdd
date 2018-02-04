(function($){
    $.fn.dekoruj = function () {
        console.log(this);
        $(this).each(function(element) {
            $(this).text('!! ' + $(this).text() + ' !!');
        });
        return this;
    }
})(jQuery);