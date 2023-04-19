let gallery = document.querySelectorAll(".gallery-item .img-responsive.grey-background");
// console.log(Array.from(gallery));
let source = ["Array"];
gallery.forEach((meme) =>
{
	let link = meme.currentSrc;
	source.push(link);
});
source.shift();
console.log("Giver Data: ", source);
return source;