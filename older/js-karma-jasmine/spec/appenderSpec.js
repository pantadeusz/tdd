// Testy napisane z wykorzystaniem frameworka jasmine

describe('plugin test', function() {
    beforeEach(function(){
        setFixtures('<div id="content"><p>hello</p></div>');
    });
    // przedrostek x oznacza, że dany test został wyłączony
    xit("initial value should be hello", function(){
        expect($('#content p').text()).toBe('hello');
        expect($('#content > input').attr('id')).not.toBe('brr');
    });
    // zwykły test
    it("should add input element by calling appendInput", function(){
        $('#content').appendInput("brr");
        expect($('#content > p').text()).toBe('hello');
        expect($('#content > input').attr('id')).toBe('brr');
    });
    // przedrostek f powoduje, że tylko testy f... się wykonają
    fit("should read property when appendInput gets an object with id field", function(){
        var o = {
            getId:function () {}
        };
        spyOn(o, 'getId'); // w jasmine mocki sa nazywane szpiegami (spy)
        $('#content').appendInput(o);
        expect(o.getId).toHaveBeenCalled();
        expect($('#content > p').text()).toBe('hello');
    });
});
