# audio

The `audio` package provides a ROS 2 composable node (`com::xhumanoid::AudioNodelet`) that drives the robot's built-in audio hardware. It handles playback of pre-loaded MP3 files stored on the robot and reacts to SBUS remote-control button events (mapped via `param/audio.json`) to cycle through audio tracks, start playback, or stop it. The node exposes its interface through the `lyre_msgs` service/topic layer and is launched as part of the full robot stack or standalone for audio-only testing.

## Launch

```bash
source install/setup.bash
ros2 launch audio audio.launch.py
```

## Examples

### Play a local audio file via ROS service

```bash
source install/setup.bash
audio_file=$(realpath $(find install -name "*.mp3" | head -1))
ros2 service call /audio_play/play_file lyre_msgs/srv/PlayFile "{path: \"${audio_file}\"}"
```

### Stop playback

```bash
ros2 service call /audio_play/stop lyre_msgs/srv/PlayStop
```

### Monitor playback events

```bash
ros2 topic echo /audio_play/event
```

### Monitor playback progress

```bash
ros2 topic echo /audio_play/progress
```
