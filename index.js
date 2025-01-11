const MyTeam = require("./build/Release/node-api-tuts.node")

try{
    ((arr)=> {
        arr.map((item)=> {
            MyTeam.addTeamMember(item)
        })
        console.log(MyTeam.getTeamList())  
    })([
        "Stanley Arua", 
        "wilma Okoli", 
        "Idris Idah", 
        "Michael Ayeyemi", 
        "Dennis Adi", 
        "James Ohia", 
        "Uriel Kasali", 
        "Musa Tanua", 
        "Musa Ibrahim"
    ])

}catch(e){
    console.error(e.message)
}

//console.log(addon.hello("Stanley"))