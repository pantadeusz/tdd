describe("cenzor tests", function() {
    var text = "bardzo lubie podatki";
    beforeEach(function(){
        var e = document.createElement('div');
        e.id = 'testelement';
        e.innerText = text;
        document.body.appendChild(e);
    });
    it("should remove every bad word from text",function() {
        expect(cenzor(text,['podatki'])).not.toContain("podatki");
    });

    it("should remove every bad word from dom element by id",function() {
        var e = document.getElementById('testelement');
        expect(e.innerText).toBe(text); // ===
        cenzor({id:'testelement',words:['podatki']});
        expect(document.getElementById('testelement').innerText).not.toContain("podatki");
        expect(e.innerText).not.toBe(text); // ===
    });
    
    afterEach(function(){
        var e = document.getElementById('testelement');
        e.parentNode.removeChild(e);
    });
});



describe("i don't like console logs, force not to use it", function(){
    var consoleSpy;
    var someSpy;
    var some = {
        print:function(v){}
    };
    beforeEach(function(){
        consoleSpy = spyOn(console,'log');
        someSpy = spyOn(some,'print').and.callFake(function(v){
            console.log('wywolano metode print ' + v);
        });
    });
    
    it('should call fake print',function(){
        some.print('bla');
        expect(consoleSpy).toHaveBeenCalledWith('wywolano metode print bla');        
    });

    fit('should call console.log',function(){
        console.log('testujemy');
        expect(consoleSpy).toHaveBeenCalledWith('testujemy');
    });

    it('should not call console.log',function(){
        expect(true).toBeTruthy();
    });

});