var buttonColors = ["orange", "yellow", "blue", "green"];

var gamePattern = [];

var userClickedPattern = [];

var started = false;

var level = 0;

$(document).keypress(function() {
  if (!started) {
    $(".heading").text("level" + level);
    randomColor();
    started = true;
  }

});



$(".btn").click(function() {
  var userChosenColor = $(this).attr("id");
  userClickedPattern.push(userChosenColor);
  playSound(userChosenColor);
  animatePress(userChosenColor);
  checkAnswer(userClickedPattern.length - 1);
});

function checkAnswer(currentLevel) {
  if (gamePattern[currentLevel] === userClickedPattern[currentLevel]) {

    console.log("success");
    if (userClickedPattern.length === gamePattern.length) {
      setTimeout(function() {
        randomColor();
      }, 1000);

    }

  } else {
    wrongSound("wrong");
    startOver();
  }

}

function wrongSound(songName) {
  var audio = new Audio("sounds/" + songName + ".mp3");
  audio.play();
  $("body").addClass("game-over");
  $(".heading").text("GAME OVER , PRESS ANY KEY TO RESTART");
  setTimeout(function() {
    $("body").removeClass("game-over");
  }, 200);
}

function randomColor() {
  userClickedPattern = [];
  level++;
  $(".heading").text("level " + level);
  var randomNumber = Math.floor(Math.random() * 4);
  var randomChosenColor = buttonColors[randomNumber];
  gamePattern.push(randomChosenColor);
  $("#" + randomChosenColor).fadeOut(100).fadeIn(100).fadeOut(100).fadeIn(100);
  playSound(randomChosenColor);
}

function playSound(name) {

  var audio = new Audio("sounds/" + name + ".mp3");
  audio.play();
}

function animatePress(currentColor) {
  $("#" + currentColor).addClass("pressed");
  setTimeout(function() {
    $("#" + currentColor).removeClass("pressed");
  }, 100);
}

$(document).keypress(function() {
  $("h2").hide();
});

function startOver() {
  level = 0;
  gamePattern = [];
  started = false;
}
