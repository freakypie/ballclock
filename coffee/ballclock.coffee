prompt = require("readline-sync")


class Track
  max: 5

  constructor: (@clock, @max, @last) ->
    @balls = []

  add: (ball) ->
    if @balls.length == @max - 1
      for b in @balls by -1
        @clock.balls.push(b)
      # @clock.balls = @clock.balls.concat @balls.reverse()
      @balls.length = 0
      return ball
    else
      @balls.push(ball)
      return null


class Clock

  constructor: (balls, expectedDays) ->
    @max = parseInt(balls)
    @expectedDays = expectedDays
    @expectedMinutes = expectedDays * 24 * 60
    @balls = []
    @tracks = [
      new Track(@, 5), # 1 minute increments (5)
      new Track(@, 12), # 5 minute increments (12)
      new Track(@, 12, true), # 1 hour (12)
    ]

    for ball in [0...@max]
      @balls.push(ball)

  tick: () ->

    # take the first ball out of the main pool
    ball = @balls.shift()

    # add to the track and trickle the ball
    for track in @tracks
      ball = track.add(ball)
      if ball is null
        break

    if ball isnt null
      @balls.push ball

    # @show()
    # prompt.question "> ready for next?:"

    return

  calc: () ->
    minutes = 0

    while minutes < @expectedMinutes
      minutes += 1
      @tick()

    return @isReset() and minutes / (60 * 24) or -1

  isReset: () ->
    index = 0

    for ball in @balls
      if ball != index
        console.log "ball", ball, index
        @show()
        return false
      index += 1

    return true

  error: (msg) ->
    console.error "\n\n  #{msg}  \n\n"

    @show()

    console.log "exiting"
    exit()

  show: () ->
    console.log "--------------"
    console.log "pool:", @balls.length

    for track in @tracks
      console.log "track:", (b for b in track.balls)


main = (num) ->

  # balls / days
  tests =
    27: 23
    28: 76
    29: 102
    30: 15
    31: 85
    32: 65
    33: 138
    34: 91
    35: 12
    36: 117
    37: 120
    38: 345
    39: 35
    40: 37
    41: 217
    42: 114
    43: 110
    44: 105
    45: 378
    46: 126
    47: 6270
    48: 12
    49: 513
    50: 1116
    51: 770
    52: 86
    53: 51
    54: 30
    55: 693
    56: 180
    57: 930
    58: 559
    59: 858
    60: 495
    61: 11067
    62: 714
    63: 455
    64: 378
    65: 84
    66: 105
    67: 12
    68: 236
    69: 7095
    70: 255
    71: 60
    72: 4524
    73: 3848
    74: 1530
    75: 1955
    76: 268
    77: 714
    78: 25389
    79: 1155
    80: 9360
    81: 2006
    82: 805
    83: 4446
    84: 1122
    85: 540
    86: 36
    87: 570
    88: 1026
    89: 11033
    90: 1218
    91: 6580
    92: 312
    93: 301
    94: 3367
    95: 42780
    96: 2550
    97: 550
    98: 1365
    99: 6630
    100: 105
    101: 861
    102: 4514
    103: 291
    104: 3960
    105: 1464
    106: 1577
    107: 4284
    108: 5187
    109: 126
    110: 17094
    111: 15330
    112: 1785
    113: 43890
    114: 25872
    115: 5762
    116: 3325
    117: 204
    118: 3420
    119: 78120
    120: 1224
    121: 776
    122: 273
    123: 108855
    124: 174
    125: 14430
    126: 80080
    127: 2415

  total = 0
  for balls, days of tests
    clock = new Clock(balls, days)
    start = Date.now()
    result = clock.calc(balls)
    time = Date.now() - start
    total += time
    console.log "#{balls} expected #{days}, returned", result
    console.log "took", time, "milliseconds"
  console.log "total time", total

main()
